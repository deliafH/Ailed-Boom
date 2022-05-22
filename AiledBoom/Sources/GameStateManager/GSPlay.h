#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Player.h"
#include"../GameObjects/Ground.h"
#include"../GameObjects/MapManager.h"
#include"../GameObjects/ScoreManager.h"
#include"../GameObjects/Item.h"
#include<vector>

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:

	Sprite *m_Background;
	Player *m_Player;

	sf::Text m_Score;
	sf::Sound* m_TimeUp, * m_Boom , * m_CoinSound;
	int m_currentScore;
	float m_currentTime, m_currentSoundTime;

	std::vector<GameButton*> m_ListBtn;
	ScoreManager* scoreManager;
	MapManager* m_Map;
	bool isDeadGround[15][10] = {}, isTimeUp, isBoom;
	std::list<Item*> m_Booms;
	Item* m_Coin;
	std::vector<Ground*> m_Grounds, m_Bridges, m_DeadGrounds;
};