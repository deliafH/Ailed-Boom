#include"Item.h"


Item::Item(int kind)
{
	this->kind = kind;
	if (kind == 1)m_Animation = new Animation(*DATA->getTexture("Item/Boom"), sf::Vector2i(5, 1), 0.6f);
	else m_Animation = new Animation(*DATA->getTexture("Item/coin"), sf::Vector2i(14, 1), 0.04f);
	Reset();
}

Item::~Item()
{
}

void Item::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
}

void Item::Reset()
{
	Position.x = rand() % 12;
	Position.y = rand() % 6;
	if(kind == 1)m_Animation->setPosition(100.f + Position.x * 70.f, 90.f + Position.y * 70.f);
	else m_Animation->setPosition(95.f + Position.x * 70.f, 90.f + Position.y * 70.f);
}

void Item::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
