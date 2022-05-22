#pragma once
#include "GameStateBase.h"
#include<vector>
class GSSettings : public GameStateBase {
public:
	GSSettings();
	virtual ~GSSettings();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::vector<GameButton*> m_ListBtn;
	sf::Sprite m_Background;
	float m_currentTime;
};