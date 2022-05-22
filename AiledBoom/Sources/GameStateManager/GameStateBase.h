#pragma once
#include"../GameManager/ResourceManager.h"
#include"GameStateMachine.h"

using namespace sf;

class GameStateBase {
public:
	GameStateBase(){}
	virtual ~GameStateBase(){}

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(RenderWindow* window) = 0;

	static GameStateBase* CreateState(StateTypes st);
};