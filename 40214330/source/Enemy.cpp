#include "Enemy.h"

Enemy::Enemy(sf::Texture &image)
{
	sprite.setTexture(image);
	rect = sf::FloatRect(1 * 49, 2 * 49.5, 49, 40);
	//sprite.setPosition(x, y);
	directionX = directionY = 0.1;
	characterFrame = 0;
	speed = 0.05f;
}

Enemy::~Enemy()
{

}

void Enemy::collision(int direction, sf::String level[])
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
	{
		for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
		{
			if (level[i][j] == '4' || level[i][j] == 'M' || level[i][j] == 'D'
				|| level[i][j] == 'd' || level[i][j] == 'G' || level[i][j] == 'Y' || level[i][j] == 'N' || level[i][j] == 'X')
			{
				if ((directionX>0) && (direction == 0)) rect.left = j * 32 - rect.width;
				if ((directionX<0) && (direction == 0)) rect.left = j * 32 + 32;
				if ((directionY>0) && (direction == 1)) { rect.top = i * 32 - rect.height; directionY = 0; grounded = true; }
				if ((directionY<0) && (direction == 1)) { rect.top = i * 32 + 32;   directionY = 0; }
			}
		}
	}
}

void Enemy::charUpdate(float dt, sf::String level[], int cameraOffsetX, int cameraOffsetY)
{
	rect.left += directionX * dt;
	collision(0, level);

	if (!grounded) directionY = directionY + 0.0005*dt;
	rect.top += directionY * dt;
	grounded = false;
	collision(1, level);

	characterFrame += 0.005*dt;
	if (characterFrame > 2) characterFrame -= 2;

	if (directionX>0) sprite.setTextureRect(sf::IntRect(49 * int(characterFrame), 99, 49, 40));
	if (directionX<0) sprite.setTextureRect(sf::IntRect(49 * int(characterFrame) + 49, 99, -49, 40));
	else
	{
		sprite.setTextureRect(sf::IntRect(49 * int(characterFrame), 140, 49, 50));
	}

	sprite.setPosition(rect.left - cameraOffsetX, rect.top - cameraOffsetY);

	directionX = 0;
}