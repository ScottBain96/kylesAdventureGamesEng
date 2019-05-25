#ifndef LEVEL_3_H
#define LEVEL_3_H
#include "GameScreen.h"
#include "Character.h"
#include "ScreenManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <SFML/Graphics.hpp>

class Level_3 : public GameScreen
{
public:
	Level_3();
	~Level_3();

	void loadContent();
	void unloadContent();
	void update(float dt, sf::Event event);
	void draw(sf::RenderWindow &window);
protected:
private:
	sf::Text text;
	sf::Font font;
	sf::Texture tilesTexture;
	sf::Sprite tiles;
	int sawAnimation;
	int movingPlatformAnimation;
};
#endif // LEVEL_3_H