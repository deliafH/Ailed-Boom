#include "PSRunDown.h"

PSRunDown::PSRunDown(IPlayer* player)
{
	m_Player = player;
}

void PSRunDown::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Down"), sf::Vector2i(4, 1), 0.2f);
}

void PSRunDown::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunDown::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRunDown::Reset()
{
	m_Animation->Reset();
}