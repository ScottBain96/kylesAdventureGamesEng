#include "Level_2.h"

Level_2::Level_2()
{
	//Constructor
}

Level_2::~Level_2()
{
	//Deconstructor
}

//Load TileMap2
sf::String TileMap2[mapHeight] = {

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
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4                                                                                                   4",
	"4       4                                                                                           4",
	"4       4                                                                                           4",
	"4       4                                              4                                  4fffffffff4",
	"4       4                                              4                                  4FFFFFFFFF4",
	"44444   4                                              4                                  4FFFFFFFFF4",
	"4   4   444444444444444444444444444444444444444444444444                                  4FFFFFFFFF4",
	"4   4   444444    44444444444444444444444444444444444444  4                               4FFFFFFFFF4",
	"4   4   444444    44444444444444444444444444444444444444     GG                           4FFFFFFFFF4",
	"4   4   444444   4444444444444444444                44444   G444                          4FFFFFFFFF4",
	"4   4   BBBBBB    BBBBBBBBBBBBBBB                   BBBB   4444              W            4FFFFFFFFF4",
	"4   4                                4444444444          Y              443333            4FFFFFFFFF4",
	"4   4        Y                        4444444                          4F43333            4FFFFFFFFF4",
	"4   4444444444444444444444444444444444444444444444444444444444444444444FF43333            4FFFFFFFFF4",
	"4       4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF43333            4FFFFFFFFF4",
	"4       4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF43333            4FFFFFFFFF4",
	"4       4444444444444444444444444444444444444444444444444444444444444444443333            4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                                         4FFFFFFFFF4",
	"4                                                                  Y                      4FFFFFFFFF4",
	"4                                              4                                          4FFFFFFFFF4",
	"4                                             444              4                          4FFFFFFFFF4",
	"4                     4             4        44444              4 4                       4FFFFFFFFF4",
	"4                  4             Y          4444444                 4                     4FFFFFFFFF4",
	"4                          4          4          Y        4           4                   4FFFFFFFFF4",
	"u                4            44   4     4444444444444                   4                4FFFFFFFFF4",
	"U               44fffffffffffffffffffffffffffffffffffffffffffffffffffffff44               4FFFFFFFFF4",
	"444444444444444444FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF444444444444444444FFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4",
	"44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444",
};

//Load all the content for the level
sf::Texture kyleTextureLevel2;
void Level_2::loadContent()
{
	//Load font, tilesheets, spritesheets, colours etc.
	if (!kyleTextureLevel2.loadFromFile("res/char.png"))
	{
		std::cout << "Cant find kyle2's spritesheet" << std::endl;
	}
	if (!tilesTexture.loadFromFile("res/tileset32x32.png"))
	{
		std::cout << "Cant find tileset" << std::endl;
	}
	tiles.setTexture(tilesTexture);
	if (!font.loadFromFile("res/myfont.ttf"))
	{
		std::cout << "Could not find the font" << std::endl;
	}
	text.setString("Level 2");
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
Character kyle2(kyleTextureLevel2);

//Call this to unload content
void Level_2::unloadContent()
{
	GameScreen::unloadContent();
}

float modifier2 = 1.0f;
void Level_2::update(float dt, sf::Event event)
{
	//If kyle2 runs out of lives then do this
	if (kyle2.lives <= 0)
	{
		kyle2.sprite.setPosition(0, 0);
	}
	//Manage key inputs via InputManager (Movement etc.)
	input.update(event);
	if (input.keyPressed(key))
	{
		if (input.keyPressed(input.controls[0])) //Left movement
		{
			kyle2.directionX = -0.1;
		}
		if (input.keyPressed(input.controls[1])) //Right movement
		{
			kyle2.directionX = 0.1;
		}
		if (input.keyPressed(input.controls[2])) //Jump movement
		{
			if (kyle2.grounded)
			{
				kyle2.directionY = -0.4;
				kyle2.grounded = false;
			}
		}
		if (input.keyPressed(input.controls[3]) && kyle2.canBoost)
		{
			if (kyle2.grounded)
			{
				kyle2.directionY = -0.75;
				kyle2.grounded = false;
			}
		}
		if (input.keyPressed(sf::Keyboard::Escape))
		{
			ScreenManager::GetInstance().addScreen(new MenuScreen);
		}
	}
	//If you reach the middle of the sceen, then keep the game centered (Render around character)
	if (kyle2.rect.left > gameWidth / 2)
	{
		kyle2.cameraOffsetX = kyle2.rect.left - gameWidth / 2;
	}
	kyle2.cameraOffsetY = kyle2.rect.top - gameHeight / 2;
	if (sawAnimation < 4)
		sawAnimation++;
	else
		sawAnimation = 1;

	if (movingPlatformAnimation == 1) modifier2 = 0.5f;
	if (movingPlatformAnimation == 160) modifier2 = -0.5f;
	movingPlatformAnimation += modifier2;

	//Update Kyle
	kyle2.charUpdate(kyle2.speed / dt, TileMap2);
	if (kyle2.canBoost)
	{
		text.setString("Boost Active - Press 'R'!");
	}
	if (kyle2.levelFinished)
	{
		ScreenManager::GetInstance().addScreen(new MenuScreen);
	}

}

void Level_2::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (TileMap2[i][j] == 'u') tiles.setTextureRect(sf::IntRect(9 * 32, 0, 32, 32)); // End of level
			if (TileMap2[i][j] == 'U') tiles.setTextureRect(sf::IntRect(9 * 32, 32, 32, 32)); // End of level
			if (TileMap2[i][j] == 'N')
			{
				tiles.setTextureRect(sf::IntRect(5 * 32, 0, 32, 32)); // FLOATING BLOCK
				tiles.setPosition(j * 32 - kyle2.cameraOffsetX, i * 32 - kyle2.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == 0.5f)
				{
					TileMap2[i][j + 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == -0.5f)
				{
					TileMap2[i][j - 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
			}
			if (TileMap2[i][j] == 'X')
			{
				tiles.setTextureRect(sf::IntRect(5 * 32, 0, 32, 32)); // FLOATING BLOCK OPPOSITE DIRECTION
				tiles.setPosition(j * 32 - kyle2.cameraOffsetX, i * 32 - kyle2.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == 0.5f)
				{
					TileMap2[i][j - 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == -0.5f)
				{
					TileMap2[i][j + 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
			}
			if (TileMap2[i][j] == 'Y')
			{
				tiles.setTextureRect(sf::IntRect(sawAnimation * 32 + 192, 2 * 32, 32, 32)); //SAW
				tiles.setPosition(j * 32 - kyle2.cameraOffsetX, i * 32 - kyle2.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == 0.5f)
				{
					TileMap2[i][j + 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier2 == -0.5f)
				{
					TileMap2[i][j - 1] = TileMap2[i][j];
					TileMap2[i][j] = ' ';
					break;
				}
			}
			if (kyle2.doorSwitch)
			{
				if (TileMap2[i][j] == 'D' || TileMap2[i][j] == 'd')continue;
			}
			else
			{
				if (TileMap2[i][j] == 'd')tiles.setTextureRect(sf::IntRect(10 * 32, 0, 32, 32)); //DOORTOP
				if (TileMap2[i][j] == 'D')tiles.setTextureRect(sf::IntRect(10 * 32, 32, 32, 32)); //DOORBOTTOM
			}
			if (TileMap2[i][j] == '4')tiles.setTextureRect(sf::IntRect(3 * 32, 0, 32, 32)); // BASIC BLOCK
			if (TileMap2[i][j] == 'M')tiles.setTextureRect(sf::IntRect(1 * 32, 2 * 32, 32, 32)); //SPIKES
			if (TileMap2[i][j] == 'B')tiles.setTextureRect(sf::IntRect(11 * 32, 32, 32, 32)); //SPIKES-UpsideDown
			if (TileMap2[i][j] == 'G')tiles.setTextureRect(sf::IntRect(7 * 32, 3 * 32, 32, 32)); //ENEMIES
			if (TileMap2[i][j] == 'F')tiles.setTextureRect(sf::IntRect(0, 2 * 32, 32, 32)); //SLIME
			if (TileMap2[i][j] == 'f')tiles.setTextureRect(sf::IntRect(0, 3 * 32, 32, 32)); //SLIMETOP
			if (kyle2.doorSwitch)
			{
				if (TileMap2[i][j] == 'E')tiles.setTextureRect(sf::IntRect(7 * 32, 0, 32, 32)); //KEYTOP - GREEN
			}
			else
				if (TileMap2[i][j] == 'E')tiles.setTextureRect(sf::IntRect(11 * 32, 2 * 32, 32, 32)); //KEYTOP - RED
			if (TileMap2[i][j] == 'W')tiles.setTextureRect(sf::IntRect(7 * 32, 32, 32, 32)); //KEYBOTTOM
			if (TileMap2[i][j] == 'J')tiles.setTextureRect(sf::IntRect(0, 32, 32, 32)); //BOOST
			if ((TileMap2[i][j] == ' ') || TileMap2[i][j] == '0' || TileMap2[i][j] == 'N' || TileMap2[i][j] == 'P' || TileMap2[i][j] == 'Y')
			{
				continue; //Skip over these
			}
			tiles.setPosition(j * 32 - kyle2.cameraOffsetX, i * 32 - kyle2.cameraOffsetY);
			window.draw(tiles);
		}
	}
	window.draw(text);
	window.draw(kyle2.sprite);
}