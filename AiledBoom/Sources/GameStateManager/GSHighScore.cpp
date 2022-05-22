#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
	scoreManager = new ScoreManager();
}

GSHighScore::~GSHighScore()
{
}

void GSHighScore::Exit()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Init()
{
	scoreManager->readFile();
	//Menu Button
	GameButton* button;
	button = new GameButton();
	button->Init("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth - screenWidth / 7.f, screenHeight - screenHeight / 4.f);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("Background/HighScore");
	m_Background.setTexture(*texture);
	m_Background.setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));

	//ListScore
	for (int i = 0; i < scoreManager->getNum(); i++) {
		sf::Text* t = new sf::Text();
		t->setString(std::to_string(scoreManager->getHighScore()[i]));
		t->setOrigin(t->getGlobalBounds().width, t->getGlobalBounds().height);
		t->setFont(*DATA->getFont("KOMIKAP_"));
		t->setPosition(screenWidth / 2 - 10.f, screenHeight / 2 - 70.f + 50 * i);
		m_ListScore.push_back(t);
	}
}

void GSHighScore::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSHighScore::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	for (auto i : m_ListScore) {
		window->draw(*i);
	}
}