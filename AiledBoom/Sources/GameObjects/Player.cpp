#include "Player.h"
#include "PSRunUp.h"
#include "PSRunDown.h"
#include "PSRunLeft.h"
#include "PSRunRight.h"
#include"PSDeath.h"

Player::Player()
{
	m_nextState = IPState::SNULL;
	m_runUpState = new PSRunUp(this);
	m_runDownState = new PSRunDown(this);
	m_runLeftState = new PSRunLeft(this);
	m_runRightState = new PSRunRight(this);
	m_deathState = new PSDeath(this);
	m_currentState = m_runDownState;
}

Player::~Player()
{
	if (m_runUpState != nullptr) {
		delete m_runUpState;
	}
	if (m_runDownState != nullptr) {
		delete m_runDownState;
	}
	if (m_runLeftState != nullptr) {
		delete m_runLeftState;
	}
	if (m_runRightState != nullptr) {
		delete m_runRightState;
	}
	if (m_deathState != nullptr) {
		delete m_deathState;
	}
	m_currentState = nullptr;

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	m_runUpState->Init();
	m_runDownState->Init();
	m_runLeftState->Init();
	m_runRightState->Init();
	m_deathState->Init();

	m_HitBox = new HitBox(sf::Vector2i(15, 30));
	m_HitBox->setPosition(100, 80);
	m_HitBox->Init(sf::Vector2f(200, 200));
	m_HitBox->SetTag(PLAYER);
}

void Player::Update(float deltaTime)
{
	if (!this->getHitBox()->isAlive()) this->changeNextState(IPState::DEATH);
	performStateChange();
	m_currentState->Update(deltaTime);
	m_NextPosition = this->getHitBox()->getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
	{
		if(m_currentState != m_runDownState)this->changeNextState(IPState::DOWN);
		m_NextPosition += sf::Vector2f(0, this->getHitBox()->getVelocity().y * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
		if(m_currentState != m_runUpState)this->changeNextState(IPState::UP);
		m_NextPosition += sf::Vector2f(0, -this->getHitBox()->getVelocity().y * deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		if(m_currentState != m_runRightState)this->changeNextState(IPState::RIGHT);
		m_NextPosition += sf::Vector2f(this->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
		if(m_currentState != m_runLeftState)this->changeNextState(IPState::LEFT);
		m_NextPosition += sf::Vector2f(-this->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	canMove = 0;
}



void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
}

void Player::Move()
{
	if (canMove)this->getHitBox()->setPosition(m_NextPosition);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::UP:
			m_currentState = m_runUpState;
			break;
		case IPState::DOWN:
			m_currentState = m_runDownState;
			break;
		case IPState::LEFT:
			m_currentState = m_runLeftState;
			break;
		case IPState::RIGHT:
			m_currentState = m_runRightState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}