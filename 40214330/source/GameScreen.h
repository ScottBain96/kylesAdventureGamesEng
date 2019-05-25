#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include "InputManager.h"

//Base class which all our screens inherit from
class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	virtual void loadContent();
	virtual void unloadContent();
	virtual void update(float dt, sf::Event event);
	virtual void draw(sf::RenderWindow &window);
	//protected members are available to the classes that inherit from this class
protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> key;
private:
};
#endif // !GAMESCREEN_H