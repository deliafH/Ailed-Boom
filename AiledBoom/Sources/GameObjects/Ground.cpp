#include "Ground.h"
Ground::Ground()
{
}

Ground::Ground(int i, int j, int kind)
{
	this->kind = kind;
	if (kind == 0)
	{
		this->setTexture(DATA->getTexture("Map/Ground"));
		this->setSize(sf::Vector2f(50.f, 50.f));
		this->setPosition(sf::Vector2f(95.f + i * 70.f, 95.f + j * 70.f));
		this->setOrigin(this->getSize() / 2.f);
	}
	else if (kind == 1)
	{
		this->setTexture(DATA->getTexture("Map/Wood Bridge"));
		this->setSize(sf::Vector2f(30.f, 50.f));
		this->setPosition(sf::Vector2f(95.f + i * 70.f, 130.f + j * 70.f));
		this->setOrigin(this->getSize() / 2.f);
	}
	else if (kind == 2)
	{
		this->setTexture(DATA->getTexture("Map/Wood Bridge2"));
		this->setSize(sf::Vector2f(100.f, 32.f));
		this->setPosition(sf::Vector2f(130.f + i * 70.f, 95.f + j * 70.f));
		this->setOrigin(this->getSize() / 2.f);
	}
	else
	{
		this->setTexture(DATA->getTexture("Map/Dead Ground"));
		this->setSize(sf::Vector2f(50.f, 50.f));
		this->setPosition(sf::Vector2f(95.f + i * 70.f, 95.f + j * 70.f));
		this->setOrigin(this->getSize() / 2.f);
	}
}

Ground::~Ground()
{
}

void Ground::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

bool Ground::isPlayerOnGround(Player* player)
{
	float right = player->getHitBox()->getPosition().x + player->getHitBox()->getSize().x / 2;
	float left = player->getHitBox()->getPosition().x - player->getHitBox()->getSize().x / 2;
	float down = player->getHitBox()->getPosition().y + player->getHitBox()->getSize().y / 2;

	if (right > this->getPosition().x + this->getSize().x / 2) return 0;
	if (left < this->getPosition().x - this->getSize().x / 2) return 0;
	if (down > this->getPosition().y + this->getSize().y / 2) return 0;
	if (down < this->getPosition().y - this->getSize().y / 2) return 0;
	return 1;
}

bool Ground::isThenPlayerOnGround(Player* player)
{
	float right = player->getNextPosition().x + player->getHitBox()->getSize().x / 2;
	float left = player->getNextPosition().x - player->getHitBox()->getSize().x / 2;
	float down = player->getNextPosition().y + player->getHitBox()->getSize().y / 2;

	if (right > this->getPosition().x + this->getSize().x / 2) return 0;
	if (left < this->getPosition().x - this->getSize().x / 2) return 0;
	if (down > this->getPosition().y + this->getSize().y / 2) return 0;
	if (down < this->getPosition().y - this->getSize().y / 2) return 0;
	return 1;
}
