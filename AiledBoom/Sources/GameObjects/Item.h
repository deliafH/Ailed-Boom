#pragma once
#include"Animation.h"
#include"../GameManager/ResourceManager.h"

class Item{
public:
	Item(int kind);
	~Item();
	void Update(float deltaTime);
	void Reset();
	void Render(sf::RenderWindow* window);

	Animation* getAnimation() { return m_Animation; }
	sf::Vector2i getPosition() { return Position; }
private:
	sf::Vector2i Position;
	Animation* m_Animation;
	int kind;
};