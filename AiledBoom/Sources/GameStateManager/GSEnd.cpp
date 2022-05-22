#include "GSEnd.h"
#include"../GameObjects/MapManager.h"
GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button;

	//Exit Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Replay Button
	button = new GameButton();
	button->Init("replay");
	button->setOnClick([]() {DATA->playMusic("GamePlay");DATA->getMusic("GamePlay")->setLoop(true); GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, screenHeight / 2 + screenHeight / 10);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Menu Button
	button = new GameButton();
	button->Init("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->playMusic("GamePlay");DATA->getMusic("GamePlay")->setLoop(true); GSM->ChangeState(StateTypes::MENU); });
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("Background/End");
	m_Background.setTexture(*texture);
	m_Background.setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));

	
}

void GSEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Score);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
