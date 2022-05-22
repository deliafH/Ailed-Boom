#pragma once
#include"GameStateBase.h"

class GSIntro : public GameStateBase {
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(RenderWindow* window);
private:
	Sprite* m_Background;
	float m_currentTime;
};
