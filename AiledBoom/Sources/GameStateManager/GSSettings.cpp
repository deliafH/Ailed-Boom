#include "GSSettings.h"
GSSettings::GSSettings()
{
}

GSSettings::~GSSettings()
{
}

void GSSettings::Exit()
{
}

void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}

void GSSettings::Init()
{
	m_currentTime = 0;
	//Menu Button
	GameButton* button;
	button = new GameButton();
	button->Init("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth - screenWidth / 7.f, screenHeight - screenHeight / 4.f);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	m_ListBtn.push_back(button);

	//Sound Button
	button = new GameButton();
	if (soundOn) button->Init("SoundOn");
	else  button->Init("SoundOff");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2.f + screenWidth / 12.f, screenHeight / 2.f + screenHeight / 7.f);
	button->setOnClick([]() {soundOn = !soundOn; });
	m_ListBtn.push_back(button);

	//MusicButton
	button = new GameButton();
	if (musicOn) button->Init("MusicOn");
	else  button->Init("MusicOff");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth/2.f - screenWidth / 12.f, screenHeight / 2.f + screenHeight / 7.f);
	button->setOnClick([]() {musicOn = !musicOn; });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background/Setting");
	m_Background.setTexture(*texture);
	m_Background.setScale(sf::Vector2f((float)screenWidth / texture->getSize().x, (float)screenHeight / texture->getSize().y));

}

void GSSettings::Update(float deltaTime)
{
	DATA->getMusic("GamePlay")->setVolume(30 * musicOn);
	m_currentTime += deltaTime;
	if (m_currentTime >= 0.1f)
	{
		m_currentTime -= 0.1f;
		if (soundOn) m_ListBtn[1]->Init("SoundOn");
		else  m_ListBtn[1]->Init("SoundOff");
		if (musicOn) m_ListBtn[2]->Init("MusicOn");
		else m_ListBtn[2]->Init("MusicOff");
	}
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSettings::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}