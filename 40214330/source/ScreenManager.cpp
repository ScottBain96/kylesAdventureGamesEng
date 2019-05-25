#include "ScreenManager.h"
#include "SplashScreen.h"
#include "MenuScreen.h"

//create stack of screen using pointers for polymorphism
GameScreen *currentScreen, *newScreen;

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager()
{
	//constructor
}

ScreenManager::~ScreenManager()
{
	//deconstructor
}

float ScreenManager::getAlpha()
{
	return fade.getAlpha();
}

//unload content on screen and then delete it, then load the new screen. stops memory leaks etc.
void ScreenManager::addScreen(GameScreen *screen)
{
	transitionActive = true;
	newScreen = screen;
	fade.setActive(true);
	fade.setAlpha(0.0f);
}

void ScreenManager::transition(float dt)
{
	if (transitionActive)
	{
		fade.update(dt);
		if (fade.getAlpha() >= 1.0f)
		{
			currentScreen->unloadContent();
			delete currentScreen;
			currentScreen = newScreen;
			currentScreen->loadContent();
			newScreen = NULL;
		}
		else if (fade.getAlpha() <= 0.0f)
		{
			transitionActive = false;
			fade.setActive(false);
		}
	}
}

void ScreenManager::initialize()
{
	currentScreen = new SplashScreen();
	transitionActive = false;
}

void ScreenManager::loadContent()
{
	currentScreen->loadContent();

	sf::Texture texture;
	sf::Vector2f position;

	fade.loadContent("", texture, position);
	fade.setAlpha(0.0f);

}

void ScreenManager::unloadContent()
{

}

void ScreenManager::update(float dt, sf::Event event)
{
	if (!transitionActive)
	{
		currentScreen->update(dt, event);
	}
	transition(dt);
}

void ScreenManager::draw(sf::RenderWindow &window)
{
	currentScreen->draw(window);
}

void ScreenManager::setText(std::string text)
{
	this->text = text;
}

void ScreenManager::drawText()
{
	std::cout << text << std::endl;
}