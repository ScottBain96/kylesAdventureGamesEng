#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <iostream>
#include "MenuScreen.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>

//Splashscreen showing game title and a backdrop
class SplashScreen : public GameScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void loadContent();
	void unloadContent();
	void update(float dt, sf::Event event);
	void draw(sf::RenderWindow &window);
protected:
private:
	sf::Text text;
	sf::Font font;
	sf::FloatRect textRect;
	sf::Texture splashScreen;
	sf::Sprite spriteBackground;
	sf::Vector2f backgroundSize;
};
#endif // SPLASHSCREEN_H