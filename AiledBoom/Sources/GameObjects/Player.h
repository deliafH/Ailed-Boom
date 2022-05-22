#pragma once
#include "IPlayer.h"
#include<list>
class Player : public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Move();
	void setCanMove() { this->canMove = 1; }
	sf::Vector2f getNextPosition() { return m_NextPosition;}

	HitBox* getHitBox();

private:
	void performStateChange();
	HitBox* m_HitBox;
	bool canMove;
	sf::Vector2f m_NextPosition;
	IPState::STATE m_nextState;
	Animation* m_Animation;
	IPState* m_currentState, * m_runUpState, * m_runDownState, * m_runLeftState, * m_runRightState, * m_deathState;
};