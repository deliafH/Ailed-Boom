#pragma once
#include "GameStateBase.h"
#include"../GameObjects/ScoreManager.h"
class GSHighScore : public GameStateBase {
public:
	GSHighScore();
	virtual ~GSHighScore();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<sf::Text*> m_ListScore;
	std::list<GameButton*> m_ListBtn;
	sf::Sprite m_Background;
	ScoreManager* scoreManager;
};