#include "MenuScreen.h"

MenuScreen::MenuScreen()
{

}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::loadContent()
{
	if (!font.loadFromFile("res/myfont.ttf"))
	{
		std::cout << "Could not find the font" << std::endl;
	}
	header.setString("Select an option:");
	header.setFont(font);
	header.setCharacterSize(40);
	header.setFillColor(sf::Color::White);
	textRect = header.getLocalBounds();
	header.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	header.setPosition(gameWidth / 2.0f, 40.0f);

	level1.setString("1.    Level 1");
	level1.setFont(font);
	level1.setCharacterSize(30);
	level1.setFillColor(sf::Color::White);
	level1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	level1.setPosition(gameWidth / 2.0f, gameHeight / 2.0f - 50.0f);

	level2.setString("2.    Level 2");
	level2.setFont(font);
	level2.setCharacterSize(30);
	level2.setFillColor(sf::Color::White);
	level2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	level2.setPosition(gameWidth / 2.0f, gameHeight / 2.0f);

	level3.setString("3.    Level 3");
	level3.setFont(font);
	level3.setCharacterSize(30);
	level3.setFillColor(sf::Color::White);
	level3.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	level3.setPosition(gameWidth / 2.0f, gameHeight / 2.0f + 50.0f);

	controls.setString("4.    Controls");
	controls.setFont(font);
	controls.setCharacterSize(30);
	controls.setFillColor(sf::Color::White);
	controls.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	controls.setPosition(gameWidth / 2.0f, gameHeight / 2.0f + 100.0f);
	controlsImageTexture.loadFromFile("res/controls.png");
	controlsImageSprite.setTexture(controlsImageTexture);
	loadControls = false;

	about.setString("5.    About");
	about.setFont(font);
	about.setCharacterSize(30);
	about.setFillColor(sf::Color::White);
	about.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	about.setPosition(gameWidth / 2.0f, gameHeight / 2.0f + 150.0f);

	exit.setString("6.    Exit");
	exit.setFont(font);
	exit.setCharacterSize(30);
	exit.setFillColor(sf::Color::White);
	exit.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	exit.setPosition(gameWidth / 2.0f, gameHeight / 2.0f + 200.0f);

	key.push_back(input.options[0]);
	key.push_back(input.options[1]);
	key.push_back(input.options[2]);
	key.push_back(input.options[3]);
	key.push_back(input.options[4]);
	key.push_back(input.options[5]);
	key.push_back(input.options[6]);
}

void MenuScreen::unloadContent()
{
	GameScreen::unloadContent();
}

void MenuScreen::update(float dt, sf::Event event)
{
	input.update(event);
	if (input.keyPressed(input.options[0]))
	{
		ScreenManager::GetInstance().addScreen(new Level_1);
	}
	if (input.keyPressed(input.options[1]))
	{
		ScreenManager::GetInstance().addScreen(new Level_2);
	}
	if (input.keyPressed(input.options[2]))
	{
		ScreenManager::GetInstance().addScreen(new Level_3);
	}
	if (input.keyPressed(input.options[3]))
	{
		loadControls = true;
	}
	if (input.keyPressed(input.options[4]))
	{
		ScreenManager::GetInstance().addScreen(new About);
	}
	if (input.keyPressed(input.options[5]))
	{
		event.type == sf::Event::Closed;
	}
	if (input.keyPressed(input.options[6]))
	{
		loadControls = false;
	}
}

void MenuScreen::draw(sf::RenderWindow &window)
{
	window.draw(header);
	window.draw(level1);
	window.draw(level2);
	window.draw(level3);
	window.draw(controls);
	window.draw(about);
	window.draw(exit);
	if (loadControls)
	{
		window.draw(controlsImageSprite);
	}
}