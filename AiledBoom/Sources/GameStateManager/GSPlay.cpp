#include "GSPlay.h"
#include<iostream>
#include<math.h>
GSPlay::GSPlay()
{
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
	m_currentSoundTime = 0.f;
	srand(time(NULL));
	m_Map = new MapManager();
	m_Player = new Player();
	m_Background = new Sprite();
	m_Player->Init();
	sf::Texture* texture = DATA->getTexture("Background/Play");
	m_Background->setTexture(*texture);
	m_Background->setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));

	//Font
	m_Score.setFont(*DATA->getFont("KOMIKABG"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setOrigin(m_Score.getGlobalBounds().width, m_Score.getGlobalBounds().height);
	m_Score.setPosition(screenWidth / 2.f + 10.f, screenHeight - 10.f);

	// Boom
	for (int i = 0; i < 5; i++)
		m_Booms.push_back(new Item(1));

	//Coin
	m_Coin = new Item(2);

	// Map
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			m_Grounds.push_back(new Ground(i, j, 0));
			m_DeadGrounds.push_back(new Ground(i, j, 3));
			if (m_Map->getPositionTurnDown(i, j))
				m_Bridges.push_back(new Ground(i, j, 1));
			if (m_Map->getPositionTurnRight(i, j))
				m_Bridges.push_back(new Ground(i, j, 2));
			isDeadGround[i][j] = 0;
			for (auto k : m_Booms)
				if (abs(k->getPosition().x - i) <= 1 && abs(k->getPosition().y - j) <= 1)
					isDeadGround[i][j] = 1;
		}
	}
	//HighScore
	scoreManager = new ScoreManager();

	//Sound
	m_TimeUp = DATA->getSound("TimeUp");
	m_Boom = DATA->getSound("Boom");
	m_CoinSound = DATA->getSound("Coin");
	isTimeUp = 0;
	isBoom = 0;

	GameButton* button;
	//Sound Button
	button = new GameButton();
	if (soundOn) button->Init("SoundOn");
	else  button->Init("SoundOff");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(Vector2f(50.f, 50.f));
	button->setPosition(screenWidth - screenWidth / 6.f, screenHeight / 10.f);
	button->setOnClick([]() {soundOn = !soundOn; });
	m_ListBtn.push_back(button);

	//MusicButton
	button = new GameButton();
	if (musicOn) button->Init("MusicOn");
	else  button->Init("MusicOff");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(Vector2f(50.f, 50.f));
	button->setPosition(screenWidth - screenWidth / 12.f, screenHeight / 10.f);
	button->setOnClick([]() {musicOn = !musicOn; });
	m_ListBtn.push_back(button);
}

void GSPlay::Update(float deltaTime)
{

	DATA->getMusic("GamePlay")->setVolume(30 * musicOn);
	m_currentSoundTime += deltaTime;
	if (m_currentSoundTime >= 0.1f)
	{
		m_currentSoundTime -= 0.1f;
		if (soundOn) m_ListBtn[0]->Init("SoundOn");
		else  m_ListBtn[0]->Init("SoundOff");
		if (musicOn) m_ListBtn[1]->Init("MusicOn");
		else m_ListBtn[1]->Init("MusicOff");
		for (auto btn : m_ListBtn) {
			btn->setSize(Vector2f(50.f, 50.f));
			btn->Update(deltaTime);
		}
	}
	
	
	//One Round Play
	if (m_Player->getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		m_Score.setString(std::to_string(m_currentScore));
		if (m_currentTime >= 5.f) {
			if (m_currentTime <= 8.f)
			{
				for (auto i : m_Booms) i->Update(deltaTime - 5.f);
				isBoom = 0;
				m_TimeUp->setVolume(50.f * soundOn);
				if (!isTimeUp)
				{
					m_TimeUp->play();
					isTimeUp = 1;
				}
			}
			else if (m_currentTime <= 10.f)
			{
				m_Boom->setVolume(50.f * soundOn);
				if (!isBoom)
				{
					m_Boom->play();
					isBoom = 1;
				}
				isTimeUp = 0;
				m_Bridges.clear();
			}
			else
			{
				for (auto i : m_Booms) i->Reset();
				m_currentTime -= 10.f;
				m_Map->Reset();
				for (int i = 0; i < 12; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (m_Map->getPositionTurnDown(i, j))
							m_Bridges.push_back(new Ground(i, j, 1));
						if (m_Map->getPositionTurnRight(i, j))
							m_Bridges.push_back(new Ground(i, j, 2));
						isDeadGround[i][j] = 0;
						for (auto k : m_Booms)
							if (abs(k->getPosition().x - i) <= 1 && abs(k->getPosition().y - j) <= 1) isDeadGround[i][j] = 1;
					}
				}
			}
		}
	}
	else scoreManager->UpdateHighScore(m_currentScore);

	//Coin
	m_Coin->Update(deltaTime);
	if (abs(m_Player->getHitBox()->getPosition().x - m_Coin->getAnimation()->getPosition().x) < 30.f && abs(m_Player->getHitBox()->getPosition().y - m_Coin->getAnimation()->getPosition().y) < 30.f)
	{
		m_CoinSound->setVolume(30.f * soundOn);
		m_Coin->Reset();
		m_currentScore += 10;
		m_CoinSound->play();
	}

	//Player
	m_Player->Update(deltaTime);
	m_Player->getHitBox()->setAlive(0);
	for (auto i : m_Bridges)
	{
		if (i->isThenPlayerOnGround(m_Player)) m_Player->setCanMove();
		if (i->isPlayerOnGround(m_Player)) m_Player->getHitBox()->setAlive(1);
	}
	for (int i = 0; i < m_Grounds.size(); i++)
	{
		if (m_Grounds[i]->isThenPlayerOnGround(m_Player)) m_Player->setCanMove();
		if ((!isDeadGround[i / 6][i % 6] || m_currentTime < 8.f) && m_Grounds[i]->isPlayerOnGround(m_Player)) m_Player->getHitBox()->setAlive(1);
	}
	m_Player->Move();
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->draw(*m_Background);

	// Map
	for (int i = 0; i < m_Grounds.size(); i++)
		if (isDeadGround[i / 6][i % 6] && m_currentTime >= 8.f) m_DeadGrounds[i]->Render(window);
	else m_Grounds[i]->Render(window);

	for (auto i : m_Bridges) i->Render(window);
	// Coin
	m_Coin->Render(window);

	//Boom
	if(m_currentTime >= 5 && m_currentTime <= 8)for (auto i : m_Booms) i->Render(window);
	m_Player->Render(window);
	window->draw(m_Score);

	//btn
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}