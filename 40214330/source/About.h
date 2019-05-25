#ifndef ABOUT_H
#define ABOUT_H
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>

class About : public GameScreen
{
public:
	About();
	~About();

	void loadContent();
	void unloadContent();
	void update(float dt, sf::Event event);
	void draw(sf::RenderWindow &window);
protected:
private:
	sf::Font font;
	sf::Text header;
	sf::Text title;
	sf::Text version;
	sf::Text author;
	sf::FloatRect textRect;
};
#endif // ABOUT_H