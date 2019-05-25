#ifndef LEVEL_2_H
#define LEVEL_2_H
#include "GameScreen.h"
#include "Character.h"
#include "ScreenManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <SFML/Graphics.hpp>

class Level_2 : public GameScreen
{
public:
	Level_2();
	~Level_2();

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
	float movingPlatformAnimation;
};
#endif // LEVEL_2_H