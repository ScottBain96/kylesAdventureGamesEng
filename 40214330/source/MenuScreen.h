#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "About.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>

class MenuScreen : public GameScreen
{
public:
	MenuScreen();
	~MenuScreen();

	void loadContent();
	void unloadContent();
	void update(float dt, sf::Event event);
	void draw(sf::RenderWindow &window);
protected:
private:
	sf::Font font;
	sf::Text header;
	sf::Text level1;
	sf::Text level2;
	sf::Text level3;
	sf::Text controls;
	sf::Texture controlsImageTexture;
	sf::Sprite controlsImageSprite;
	sf::Text about;
	sf::Text exit;
	sf::FloatRect textRect;
	bool loadControls;
};
#endif // MENUSCREEN_H