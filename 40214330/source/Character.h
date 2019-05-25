#ifndef CHARACTER_H
#define CHARACTER_H
#include "Game.h"
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite
{
public:
	float directionX, directionY;
	sf::FloatRect rect;
	bool grounded;
	Sprite sprite;
	float characterFrame;
	int lives;
	float speed;
	bool doorSwitch;
	bool canBoost;
	bool levelFinished;
	float cameraOffsetX, cameraOffsetY;

	Character(sf::Texture &image);
	~Character();

	void collision(int direction, sf::String level[]);
	void charUpdate(float dt, sf::String level[]);
};
#endif //!CHARACTER_H