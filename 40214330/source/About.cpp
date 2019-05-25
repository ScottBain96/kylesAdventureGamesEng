#include "About.h"

About::About()
{

}

About::~About()
{

}

void About::loadContent()
{
	if (!font.loadFromFile("res/myfont.ttf"))
	{
		std::cout << "Could not find the font" << std::endl;
	}
	header.setString("            About            ");
	header.setFont(font);
	header.setCharacterSize(40);
	header.setFillColor(sf::Color::White);
	textRect = header.getLocalBounds();
	header.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	header.setPosition(gameWidth / 2.0f, 40.0f);

	title.setString("Kyle's Adventure              ");
	title.setFont(font);
	title.setCharacterSize(25);
	title.setFillColor(sf::Color::White);
	title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	title.setPosition(gameWidth / 2.0f, gameHeight / 2.0f - 50.0f);

	version.setString("Version: 1.0                ");
	version.setFont(font);
	version.setCharacterSize(25);
	version.setFillColor(sf::Color::White);
	version.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	version.setPosition(gameWidth / 2.0f, gameHeight / 2.0f);

	author.setString("Author:    W Daglish & S Bain");
	author.setFont(font);
	author.setCharacterSize(25);
	author.setFillColor(sf::Color::White);
	author.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	author.setPosition(gameWidth / 2.0f, gameHeight / 2.0f + 50.0f);

	key.push_back(sf::Keyboard::Escape);
}

void About::unloadContent()
{
	GameScreen::unloadContent();
}

void About::update(float dt, sf::Event event)
{
	if (input.keyPressed(sf::Keyboard::Escape))
	{
		ScreenManager::GetInstance().addScreen(new MenuScreen);
	}
}

void About::draw(sf::RenderWindow &window)
{
	window.draw(header);
	window.draw(title);
	window.draw(version);
	window.draw(author);
}