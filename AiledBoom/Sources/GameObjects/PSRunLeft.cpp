#include "PSRunLeft.h"

PSRunLeft::PSRunLeft(IPlayer* player)
{
	m_Player = player;
}

void PSRunLeft::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Left"), sf::Vector2i(4, 1), 0.2f);
}

void PSRunLeft::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunLeft::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRunLeft::Reset()
{
	m_Animation->Reset();
}