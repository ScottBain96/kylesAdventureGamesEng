#include "Level_3.h"

Level_3::Level_3()
{
	//Constructor
}

Level_3::~Level_3()
{
	//Deconstructor
}

//Load TileMap
sf::String TileMap3[mapHeight] = {
	"44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                             4444444444444444444                                   4",
	"4                                                                                                   4",
	"4                   4444444444  4444444                                                             4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4   4444444444444444444                                                                             4",
	"4                                                                                                   4",
	"4                  4444444444444   444444444444444    4444444444444444444                           4",
	"4                                                                                                   4",
	"4444444                                                                                             4",
	"4     4                                                                                             4",
	"4     4                                       4444444444444444444                                   4",
	"4     4                                                                                             4",
	"4     4                                                                                             4",
	"4     4                     4                               4                                       4",
	"4     4                                               4                                             4",
	"4     4                                                                                             4",
	"4     4                                           44                                                4",
	"4     4                 4         4                           4444                                  4",
	"4     4                       4                    444                                              4",
	"4     4                    44 4                 4                 444                               4",
	"4     4                       4                                                                     4",
	"4     4                   44444                               444                                   4",
	"4     4                 4                                     N                                     4",
	"4     444444444444                      4           4      4      4444                              4",
	"4                4     444                      4      N                                            4",
	"4                4                          4                                                       4",
	"4                4   444            4444                 4   444444444444444444444444444444444      4",
	"4                4                                           4444444444444444444444444444444444     4",
	"4                4                                           44444444444444444444444444444444444    4",
	"4                4fffffffffffffffffffffffff4    4ffffffffffffFFFFFFFFFFFFFFFFFFFF4444444444444444   4",
	"4                4FFFFFFFFFFFFFFFFFFFFFFFFF444444FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF44444444444444444  4",
	"4                4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF44444444444444444  4",
	"4                4FFFFFFFFFFFFFFFFFFFFFFFFF444444FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4                  4",
	"4                444444444444444444444444444    4444444444444444444444444444444444                  4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                           444444444",
	"44444                                                                                      4444444444",
	"4   4                                                                                     44FFFFFFFF4",
	"4   4                                                                                    44FFFFFFFFF4",
	"4   u                                                                                   44FFFFFFFFFF4",
	"4B  U                                                                                  444FFFFFFFFFF4",
	"4444444444444                           44444444444444444444444444444444444444444444444444FFFFFFFFFF4",
	"444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444FFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444",
};

//Load all the content for the level
sf::Texture spritesheet3;
sf::Texture boss;
sf::Sprite bossSprite;
void Level_3::loadContent()
{
	//Load font, tilesheets, spritesheets, colours etc.
	if (!spritesheet3.loadFromFile("res/char.png"))
	{
		std::cout << "Cant find kyle3's spritesheet" << std::endl;
	}
	if (!boss.loadFromFile("res/scientistSprite.png"))
	{
		std::cout << "Cant find boss spritesheet" << std::endl;
	}
	if (!tilesTexture.loadFromFile("res/tileset32x32.png"))
	{
		std::cout << "Cant find tileset" << std::endl;
	}
	tiles.setTexture(tilesTexture);
	bossSprite.setTexture(boss);
	if (!font.loadFromFile("res/myfont.ttf"))
	{
		std::cout << "Could not find the font" << std::endl;
	}
	text.setString("Level 3");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	sawAnimation = 0;
	movingPlatformAnimation = 0;

	//Load Controls
	key.push_back(input.controls[0]);
	key.push_back(input.controls[1]);
	key.push_back(input.controls[2]);
	key.push_back(input.controls[3]);
	key.push_back(sf::Keyboard::Escape);
}

//Load Player
Character kyle3(spritesheet3);
Enemy enemies(spritesheet3);

//Call this to unload content
void Level_3::unloadContent()
{
	GameScreen::unloadContent();
}

int startTimer = 0;
float modifier3 = 0.25f;
float e_x = 0, e_y = 0, e_speed = 0.5f;   //Enemy Movement towards player
void Level_3::update(float dt, sf::Event event)
{
	//Manage key inputs via InputManager (Movement etc.)
	input.update(event);
	if (input.keyPressed(key))
	{
		if (input.keyPressed(input.controls[0])) //Left movement
		{
			kyle3.directionX = -0.1;
		}
		if (input.keyPressed(input.controls[1])) //Right movement
		{
			kyle3.directionX = 0.1;
		}
		if (input.keyPressed(input.controls[2])) //Jump movement
		{
			if (kyle3.grounded)
			{
				kyle3.directionY = -0.35;
				kyle3.grounded = false;
			}
		}
		if (input.keyPressed(input.controls[3]) && kyle3.canBoost)
		{
			if (kyle3.grounded)
			{
				kyle3.directionY = -0.75;
				kyle3.grounded = false;
			}
		}
		if (input.keyPressed(sf::Keyboard::Escape))
		{
			ScreenManager::GetInstance().addScreen(new MenuScreen);
		}
	}
	//If you reach the middle of the sceen, then keep the game centered (Render around character)
	if (kyle3.rect.left > gameWidth / 2)
	{
		kyle3.cameraOffsetX = kyle3.rect.left - gameWidth / 2;
	}
	kyle3.cameraOffsetY = kyle3.rect.top - gameHeight / 2;
	if (sawAnimation < 4)
		sawAnimation++;
	else
		sawAnimation = 1;

	if (movingPlatformAnimation == 1) modifier3 = 0.25f;
	if (movingPlatformAnimation == 160)modifier3 = -0.25f;
	movingPlatformAnimation += modifier3;
	kyle3.charUpdate(10, TileMap3);
	//if (std::abs(enemies.sprite.getPosition().x - kyle3.sprite.getPosition().x) < 128)

	if (enemies.sprite.getPosition().x < kyle3.sprite.getPosition().x)
	{
		e_x = e_speed;   //Moves to right
		enemies.directionX = 0.1;
	}

	else if (enemies.sprite.getPosition().x > kyle3.sprite.getPosition().x)
	{
		e_x = -e_speed;   //Moves to left
		enemies.directionX = -0.1;
	}

	if (enemies.sprite.getPosition().y < kyle3.sprite.getPosition().y)
	{
		e_y = e_speed;   //Moves down
		enemies.directionY = 0.1;
	}

	else if (enemies.sprite.getPosition().y > kyle3.sprite.getPosition().y)
	{
		e_y = -e_speed;   //Moves up
		enemies.directionY = -0.1;
	}
	//enemies.sprite.move(e_x, e_y);   //Enemy movement
	enemies.charUpdate(enemies.speed / dt, TileMap3, kyle3.cameraOffsetX, kyle3.cameraOffsetY);
	startTimer++;
	if (enemies.sprite.getGlobalBounds().intersects(kyle3.sprite.getGlobalBounds()) && startTimer > 200)
	{
		kyle3.lives = kyle3.lives -1;
		startTimer = 0;
	}
	//If kyle reaches the exit he completes the level
	if (kyle3.levelFinished)
	{
		ScreenManager::GetInstance().addScreen(new MenuScreen);
	}
}

void Level_3::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (TileMap3[i][j] == 'B')
			{
				bossSprite.setTextureRect(sf::IntRect(2 * 28, 0, 32, 32)); // BOSS
				bossSprite.setPosition(j * 32 - kyle3.cameraOffsetX, i * 32 - kyle3.cameraOffsetY);
			}
			if (TileMap3[i][j] == '4')tiles.setTextureRect(sf::IntRect(3 * 32, 0, 32, 32)); // BASIC BLOCK
			if (TileMap3[i][j] == 'N')tiles.setTextureRect(sf::IntRect(5 * 32, 0, 32, 32)); // FLOATING BLOCK
			if (TileMap3[i][j] == 'Y')tiles.setTextureRect(sf::IntRect(7 * 32, 2 * 32, 32, 32)); //SAW
			if (kyle3.doorSwitch)
			{
				if (TileMap3[i][j] == 'D' || TileMap3[i][j] == 'd')continue;
			}
			else
			{
				if (TileMap3[i][j] == 'd')tiles.setTextureRect(sf::IntRect(8 * 32, 2 * 32, 32, 32)); //DOORTOP
				if (TileMap3[i][j] == 'D')tiles.setTextureRect(sf::IntRect(8 * 32, 32, 32, 32)); //DOORBOTTOM
			}
			if (TileMap3[i][j] == 'M')tiles.setTextureRect(sf::IntRect(1 * 32, 2 * 32, 32, 32)); //SPIKES
			if (TileMap3[i][j] == 'G')tiles.setTextureRect(sf::IntRect(8 * 32, 3 * 32, 32, 32)); //ENEMIES
			if (TileMap3[i][j] == 'f')tiles.setTextureRect(sf::IntRect(0, 3 * 32, 32, 32)); //SLIME
			if (TileMap3[i][j] == 'F')tiles.setTextureRect(sf::IntRect(0, 2 * 32, 32, 32)); //SLIME
			if (TileMap3[i][j] == 'W')tiles.setTextureRect(sf::IntRect(7 * 32, 32, 32, 32)); //KEY
			if (TileMap3[i][j] == 'J')tiles.setTextureRect(sf::IntRect(0, 32, 32, 32)); //BOOST
			if ((TileMap3[i][j] == ' ') || TileMap3[i][j] == '0')
			{
				continue; //Skip over these
			}
			tiles.setPosition(j * 32 - kyle3.cameraOffsetX, i * 32 - kyle3.cameraOffsetY);
			window.draw(tiles);
		}
	}
	window.draw(text);
	window.draw(kyle3.sprite);
	window.draw(enemies.sprite);
	window.draw(bossSprite);
}