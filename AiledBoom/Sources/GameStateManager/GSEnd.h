#pragma once
#include"GameStateBase.h"

class GSEnd : public GameStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setCurrentScore(int currentScore) { this->m_CurrentScore = currentScore; };
private:
	int m_CurrentScore;
	sf::Text m_Score;
	std::list<GameButton*> m_ListBtn;
	sf::Sprite m_Background;
};
