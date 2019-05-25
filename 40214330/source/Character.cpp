#include "Character.h"

Character::Character(sf::Texture &image)
{
	sprite.setTexture(image);
	rect = sf::FloatRect(1 * 32.6, 1 * 49.5, 32, 40);

	directionX = directionY = 0.1;
	characterFrame = 0;
	speed = 0.1f;
	lives = 1;
	cameraOffsetX = 0;
	cameraOffsetY = 0;
	levelFinished = false;
	canBoost = false;
	doorSwitch = false;
}

Character::~Character()
{

}

//Check for collision with any tiles for kyle's sprite
void Character::collision(int direction, sf::String level[])
{
	//CHECK FOR TILES 32 * 32 AROUND KYLE
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
	{
		for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
		{
			//IF A SOLID TILE THEN COLLIDE (OFFSET KYLE BY THE TILE SIZE (32 * 32)
			if (level[i][j] == '4' || level[i][j] == 'M' || (!doorSwitch && level[i][j] == 'D')
				|| (!doorSwitch && level[i][j] == 'd') || level[i][j] == 'G' || level[i][j] == 'Y' || level[i][j] == 'N' || level[i][j] == 'X')
			{
				if ((directionX>0) && (direction == 0)) rect.left = j * 32 - rect.width;
				if ((directionX<0) && (direction == 0)) rect.left = j * 32 + 32;
				if ((directionY>0) && (direction == 1)) { rect.top = i * 32 - rect.height; directionY = 0; grounded = true; }
				if ((directionY<0) && (direction == 1)) { rect.top = i * 32 + 32;   directionY = 0; }
			}
			//If kyle hits a switch "W" then the doors open
			if (level[i][j] == 'W')
			{
				doorSwitch = true;
			}
			if (level[i][j] == 'G' || level[i][j] == 'F' || level[i][j] == 'Y' || level[i][j] == 'M' || level[i][j] == 'B')
			{
				lives = lives - 1;
			}
			//IF THIS TILE THEN DELETE "ABSORB" TILE WHEN IN CONTACT
			//Kyle also gains the "Boost" ability
			if (level[i][j] == 'J')
			{
				level[i][j] = ' ';
				canBoost = true;
			}
			if (level[i][j] == 'U')
			{
				levelFinished = true;
			}
			if (level[i][j] == 'B')
			{
				levelFinished = true;
			}
		}
	}
}

//Update kyle's sprite
void Character::charUpdate(float dt, sf::String level[])
{
	//RESET KYLE IF HE RUNS OUT OF LIVES
	if (lives < 1)
	{
		rect = sf::FloatRect(1 * 32.6, 1 * 49.5, 32, 40);
		directionX = directionY = 0.1;
		characterFrame = 0;
		cameraOffsetX = 0;
		cameraOffsetY = 0;
		sprite.setPosition(0, 0);
		lives = 1;
	}
	rect.left += directionX * dt;
	collision(0, level);

	if (!grounded) directionY = directionY + 0.0005*dt;
	rect.top += directionY * dt;
	grounded = false;
	collision(1, level);

	characterFrame += 0.005*dt;
	if (characterFrame > 2) characterFrame -= 2;

	//Change Kyle's sprite for each frame to show him "moving"
	if (directionX>0) sprite.setTextureRect(sf::IntRect(32.6 * int(characterFrame), 49.5, 32, 40));
	if (directionX<0) sprite.setTextureRect(sf::IntRect(32.6 * int(characterFrame) + 32.6, 49.5, -32, 40));

	sprite.setPosition(rect.left - cameraOffsetX, rect.top - cameraOffsetY);

	directionX = 0;
}