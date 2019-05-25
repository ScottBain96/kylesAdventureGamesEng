#ifndef ENEMY_H
#define ENEMY_H
#include "Game.h"
#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite
{
public:
	float directionX, directionY;
	sf::FloatRect rect;
	bool grounded;
	Sprite sprite;
	float characterFrame;
	float speed;

	Enemy(sf::Texture &image);
	~Enemy();
	void collision(int direction, sf::String level[]);
	void charUpdate(float dt, sf::String level[], int cameraOffsetX, int cameraOffsetY);
protected:
private:
};
#endif //!ENEMY_H