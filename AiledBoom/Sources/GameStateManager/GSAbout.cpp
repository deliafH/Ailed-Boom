#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{

	//Menu Button
	GameButton* button;
	button = new GameButton();
	button->Init("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth - screenWidth / 7.f, screenHeight - screenHeight / 4.f);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("Background/About");
	m_Background.setTexture(*texture);
	m_Background.setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));

}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}