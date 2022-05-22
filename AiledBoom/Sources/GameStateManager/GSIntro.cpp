#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_currentTime = 0;
	m_Background = new Sprite();
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("Background/Intro");
	m_Background->setTexture(*texture);
	m_Background->setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 3.f)
	{
		DATA->playMusic("GamePlay");
		DATA->getMusic("GamePlay")->setLoop(true);
		GSM->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(RenderWindow* window)
{
	window->draw(*m_Background);
}
