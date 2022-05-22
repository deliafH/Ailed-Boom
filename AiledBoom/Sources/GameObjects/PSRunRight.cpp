#include "PSRunRight.h"

PSRunRight::PSRunRight(IPlayer* player)
{
	m_Player = player;
}

void PSRunRight::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Right"), sf::Vector2i(4, 1), 0.2f);
}

void PSRunRight::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunRight::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRunRight::Reset()
{
	m_Animation->Reset();
}