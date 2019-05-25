#include "SplashScreen.h"

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::loadContent()
{
	if (!font.loadFromFile("res/myfont.ttf"))
	{
		std::cout << "Could not find the font" << std::endl;
	}
	text.setString("Kyle's Adventure");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(gameWidth / 2.0f, gameHeight / 2.5f);
	splashScreen.loadFromFile("res/splashscreen.jpg");
	spriteBackground.setTexture(splashScreen);
	spriteBackground.setPosition(0, 0);
	backgroundSize.x = 900.0f, backgroundSize.y = 1200.0f;
	//spriteBackground.setScale(backgroundSize.x / spriteBackground.getLocalBounds().width, backgroundSize.y / spriteBackground.getLocalBounds().height);
	key.push_back(sf::Keyboard::Return);
}

void SplashScreen::unloadContent()
{
	GameScreen::unloadContent();
}

void SplashScreen::update(float dt, sf::Event event)
{
	input.update(event);
	if (input.keyPressed(key))
	{
		ScreenManager::GetInstance().addScreen(new MenuScreen);
	}
}

void SplashScreen::draw(sf::RenderWindow &window)
{
	window.draw(spriteBackground);
	window.draw(text);
}