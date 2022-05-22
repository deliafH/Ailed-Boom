#include "PSRunUp.h"

PSRunUp::PSRunUp(IPlayer* player)
{
	m_Player = player;
}

void PSRunUp::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Up"), sf::Vector2i(4, 1), 0.2f);
}

void PSRunUp::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunUp::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRunUp::Reset()
{
	m_Animation->Reset();
}