#pragma once
#include"../GameManager/ResourceManager.h"
#include"Player.h"

class Ground : public sf::RectangleShape
{
public:
	Ground();
	Ground(int i, int j, int kind);
	~Ground();

	void Render(sf::RenderWindow* window);
	bool isPlayerOnGround(Player* player);
	bool isThenPlayerOnGround(Player* player);
private:
	int kind;
};