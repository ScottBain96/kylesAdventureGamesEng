#ifndef LEVEL_1_H
#define LEVEL_1_H
#include "GameScreen.h"
#include "Character.h"
#include "Enemy.h"
#include "ScreenManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <SFML/Graphics.hpp>

class Level_1 : public GameScreen
{
public:
	Level_1();
	~Level_1();

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
#endif // LEVEL_1_H