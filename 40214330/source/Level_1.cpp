#include "Level_1.h"



Level_1::Level_1()
{
	//Constructor
}

Level_1::~Level_1()
{
	//Deconstructor
}

//Load TileMap1
sf::String TileMap1[mapHeight] = {
	"44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444",
	"4             4                                     4                                               4",
	"4             4                                     4                                               4",
	"4             4                                     4                                               4",
	"4             4                                     4                                               4",
	"4             4                                     4                                               4",
	"4             4          44   P    44               4                                               4",
	"4             4                                     4                                               4",
	"4             4    44           4444                4                                               4",
	"4             4     Y              4                4                                               4",
	"4             4                    4   E            4                                               4",
	"4             444                  4   W            4                                               4",
	"4             4                    444444444444     4                                               4",
	"4             4    444444444      44          4     4                                               4",
	"4             4    4       44    44           4     4                                               4",
	"4             444444       4                  4  44444444                                           4",
	"4                          4                  4         4                                           4",
	"4                          44444444444        4         4                                           4",
	"4                                         44444         4                                           4",
	"4                       4                     4         4                                           4",
	"4             N         44               44   4444444   4                                           4",
	"4                       44                    4         4                                           4",
	"4     444        N      44  44444444444  4     4         4                                          4",
	"4          N         44 44           4MMMMMMMM4         4                                           4",
	"4444                    44           4444444444   4444444                                           4",
	"4                       4444444444                      4                                           4",
	"4                                                44444444                                           4",
	"4    444                    G  G G               4FFFFFF4                                           4",
	"4                      44444444444   44      444  4FFFFFF4                                          4",
	"4    MMMMMMMMMMMMMMMM444FFFFFFFFF4     4       4  4FFFFFF4                                          4",
	"4    4444444444444444444FFFFFFFFF4      4      4FFFF444444                                          4",
	"4                      44444444444       4    4FFFFFFFFF4                                           4",
	"4                             d                 4FFFFFFFFF4                                         4",
	"4                             D              4 4444444444444444444444444444444444444444             4",
	"4                             44444444444444444                                      4              4",
	"4                             4                                                      4              4",
	"4                     444444444                                                      4              4",
	"44    4                4                                                              4             4",
	"444  44                4                                                              4             4",
	"4 4  4                 4                                                              4             4",
	"4 4  4            444444                                                              4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4      4444444444444444444444                                                    4             4",
	"4 4  4       44444444444444444444                                                     4             4",
	"4 4  4        444444444444444444                                                      4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                                                                4             4",
	"4 4  4                                  44444444                                      4             4",
	"4 4  4                                 44FFFFFF44                                     4             4",
	"4 4  4 J        Y                     444FFFFFF444                                44444             4",
	"4 4  444444444444444444444444444444444444444444444444         4444444444          4                 4",
	"4 4                                                 4           4       4         4                 4",
	"4 4                                                 4           4       4   4444444                 4",
	"4 444444444444444444444444444444444444444444444444  4           4       4   4444444                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       44444     4                 4",
	"4                                                4  4           4       44444     4                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       4         4                 4",
	"4                                                4  4           4       u         4                 4",
	"4                                                4  4MMMMMMMMMMM4       U         4                 4",
	"4                                                4  4444444444444       44444444444                 4",
	"4                                                4                          4                       4",
	"4                                                4                    4444444                       4",
	"44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444",
};

//Load all the content for the level
sf::Texture spritesheet1;
void Level_1::loadContent()
{
	//Load font, tilesheets, spritesheets, colours etc.
	if (!spritesheet1.loadFromFile("res/char.png"))
	{
		std::cout << "Cant find kyle1's spritesheet" << std::endl;
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
Character kyle1(spritesheet1);

//Call this to unload content
void Level_1::unloadContent()
{
	GameScreen::unloadContent();
}

float modifier1 = 1.0f;
void Level_1::update(float dt, sf::Event event)
{
	//Manage key inputs via InputManager (Movement etc.)
	input.update(event);
	if (input.keyPressed(key))
	{
		if (input.keyPressed(input.controls[0])) //Left movement
		{
			kyle1.directionX = -0.1;
		}
		if (input.keyPressed(input.controls[1])) //Right movement
		{
			kyle1.directionX = 0.1;
		}
		if (input.keyPressed(input.controls[2])) //Jump movement
		{
			if (kyle1.grounded)
			{
				kyle1.directionY = -0.35;
				kyle1.grounded = false;
			}
		}
		if (input.keyPressed(input.controls[3]) && kyle1.canBoost)
		{
			if (kyle1.grounded)
			{
				kyle1.directionY = -0.75;
				kyle1.grounded = false;
			}
		}
		if (input.keyPressed(sf::Keyboard::Escape))
		{
			ScreenManager::GetInstance().addScreen(new MenuScreen);
		}
	}
	//If you reach the middle of the sceen, then keep the game centered (Render around character)
	if (kyle1.rect.left > gameWidth / 2)
	{
		kyle1.cameraOffsetX = kyle1.rect.left - gameWidth / 2;
	}
	kyle1.cameraOffsetY = kyle1.rect.top - gameHeight / 2;

	//Counter for rotating saws
	if (sawAnimation < 4)
		sawAnimation++;
	else
		sawAnimation = 1;

	//Counter to move the platforms back and forward every "32" pixels / 1 block (32x32)
	if (movingPlatformAnimation == 1) modifier1 = 0.25f;
	if (movingPlatformAnimation == 160) modifier1 = -0.25f;
	movingPlatformAnimation += modifier1;

	//If kyle gets the boost power up then he can Jump higher
	if (kyle1.canBoost)
	{
		text.setString("Boost Active - Press 'R'!");
	}
	//If kyle reaches the exit he completes the level
	if (kyle1.levelFinished)
	{
		ScreenManager::GetInstance().addScreen(new MenuScreen);
	}

	//Update Kyle
	kyle1.charUpdate(kyle1.speed / dt, TileMap1);
}

//Draw everything
void Level_1::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (TileMap1[i][j] == 'u') tiles.setTextureRect(sf::IntRect(9 * 32, 0, 32, 32)); // End of level
			if (TileMap1[i][j] == 'U') tiles.setTextureRect(sf::IntRect(9 * 32, 32, 32, 32)); // End of level
			if (TileMap1[i][j] == 'N')
			{
				tiles.setTextureRect(sf::IntRect(5 * 32, 0, 32, 32)); // FLOATING BLOCK
				tiles.setPosition(j * 32 - kyle1.cameraOffsetX, i * 32 - kyle1.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == 0.25f)
				{
					TileMap1[i][j + 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == -0.25f)
				{
					TileMap1[i][j - 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
			}
			if (TileMap1[i][j] == 'P')
			{
				tiles.setTextureRect(sf::IntRect(sawAnimation * 32 + 192, 2 * 32, 32, 32)); //SAW
				tiles.setPosition(j * 32 - kyle1.cameraOffsetX, i * 32 - kyle1.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == 0.25f)
				{
					TileMap1[i + 1][j] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == -0.25f)
				{
					TileMap1[i - 1][j] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
			}
			if (TileMap1[i][j] == 'X')
			{
				tiles.setTextureRect(sf::IntRect(5 * 32, 0, 32, 32)); // FLOATING BLOCK OPPOSITE DIRECTION
				tiles.setPosition(j * 32 - kyle1.cameraOffsetX, i * 32 - kyle1.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == 0.25f)
				{
					TileMap1[i][j - 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == -0.25f)
				{
					TileMap1[i][j + 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
			}
			if (TileMap1[i][j] == 'Y')
			{
				tiles.setTextureRect(sf::IntRect(sawAnimation * 32 + 192, 2 * 32, 32, 32)); //SAW
				tiles.setPosition(j * 32 - kyle1.cameraOffsetX, i * 32 - kyle1.cameraOffsetY);
				//tiles.move(movingPlatformAnimation, 0);
				window.draw(tiles);
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == 0.25f)
				{
					TileMap1[i][j + 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
				if ((movingPlatformAnimation == 1 || movingPlatformAnimation == 32 || movingPlatformAnimation == 64 ||
					movingPlatformAnimation == 96 || movingPlatformAnimation == 128 || movingPlatformAnimation == 160) && modifier1 == -0.25f)
				{
					TileMap1[i][j - 1] = TileMap1[i][j];
					TileMap1[i][j] = ' ';
					break;
				}
			}
			if (kyle1.doorSwitch)
			{
				if (TileMap1[i][j] == 'D' || TileMap1[i][j] == 'd')continue;
			}
			else
			{
				if (TileMap1[i][j] == 'd')tiles.setTextureRect(sf::IntRect(10 * 32, 0, 32, 32)); //DOORTOP
				if (TileMap1[i][j] == 'D')tiles.setTextureRect(sf::IntRect(10 * 32, 32, 32, 32)); //DOORBOTTOM
			}
			if (TileMap1[i][j] == '4')tiles.setTextureRect(sf::IntRect(3 * 32, 0, 32, 32)); // BASIC BLOCK
			if (TileMap1[i][j] == 'M')tiles.setTextureRect(sf::IntRect(1 * 32, 2 * 32, 32, 32)); //SPIKES
			if (TileMap1[i][j] == 'B')tiles.setTextureRect(sf::IntRect(11 * 32, 32, 32, 32)); //SPIKES-UpsideDown
			if (TileMap1[i][j] == 'G')tiles.setTextureRect(sf::IntRect(7 * 32, 3 * 32, 32, 32)); //ENEMIES
			if (TileMap1[i][j] == 'F')tiles.setTextureRect(sf::IntRect(0, 2 * 32, 32, 32)); //SLIME
			if (TileMap1[i][j] == 'f')tiles.setTextureRect(sf::IntRect(0, 3 * 32, 32, 32)); //SLIMETOP
			if (kyle1.doorSwitch)
			{
				if (TileMap1[i][j] == 'E')tiles.setTextureRect(sf::IntRect(7 * 32, 0, 32, 32)); //KEYTOP - GREEN
			}
			else
				if (TileMap1[i][j] == 'E')tiles.setTextureRect(sf::IntRect(11 * 32, 2 * 32, 32, 32)); //KEYTOP - RED
			if (TileMap1[i][j] == 'W')tiles.setTextureRect(sf::IntRect(7 * 32, 32, 32, 32)); //KEYBOTTOM
			if (TileMap1[i][j] == 'J')tiles.setTextureRect(sf::IntRect(0, 32, 32, 32)); //BOOST
			if ((TileMap1[i][j] == ' ') || TileMap1[i][j] == '0' || TileMap1[i][j] == 'N' || TileMap1[i][j] == 'P' || TileMap1[i][j] == 'Y')
			{
				continue; //Skip over these
			}
			tiles.setPosition(j * 32 - kyle1.cameraOffsetX, i * 32 - kyle1.cameraOffsetY);
			window.draw(tiles);
		}
	}
	window.draw(text);
	window.draw(kyle1.sprite);
}