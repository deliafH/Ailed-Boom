#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 1.f;
}

void PSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Up"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSDeath::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	GSM->ChangeState(StateTypes::END);
	DATA->getMusic("GamePlay")->stop();
	DATA->playMusic("Lose");
	DATA->getMusic("Lose")->setVolume(50.f * soundOn);

	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}