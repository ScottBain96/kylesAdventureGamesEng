#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "ScreenManager.h"
#include "Character.h"
using namespace sf;
using namespace std;

//Create Event
Event event;
//Variables for delta time and fps calc
float dt;
float frametimes[256] = {};
uint8_t ftc = 0;
const string gameName = "Kyle's Adventure";
// Create a video mode object
VideoMode vm(gameWidth, gameHeight, 64);
// Create and open a window for the game
RenderWindow window(vm, gameName, Style::Default);
//Rectangle for "fading" effect between states
RectangleShape fade;

void Load()
{
	ScreenManager::GetInstance().initialize();
	ScreenManager::GetInstance().loadContent();
	fade.setPosition(0, 0);
	fade.setSize(Vector2f(gameWidth, gameHeight));
	fade.setFillColor(Color(255, 255, 255));
}

void Update(RenderWindow &window)
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	{
		frametimes[++ftc] = dt;
		sf::String avg = gameName + " FPS: ";
		if (ftc % 60 == 0)
		{
			double davg = 0;
			for (const auto t : frametimes)
			{
				davg += t;
			}
			davg = 1.0 / (davg / 255.0);
			auto test = std::to_string(davg);
			window.setTitle(avg + test);
		}
	}
	ScreenManager::GetInstance().update(dt, event);
	fade.setFillColor(Color(0, 0, 0, 255 * ScreenManager::GetInstance().getAlpha()));
	// check and consume events
	while (window.pollEvent(event))
	{
		window.setKeyRepeatEnabled(false);
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}
}

void Render(RenderWindow &window)
{
	ScreenManager::GetInstance().draw(window);
	window.draw(fade);
}

int main()
{
	//Game music
	Music music;
	if (!music.openFromFile("res/audio/levelTheme.ogg"))
	{
		std::cout << "Cant find audio 'mainTheme.ogg'" << std::endl;
	}
	music.setVolume(30);
	music.play();
	Load();
	while (window.isOpen())
	{
		// Clear everything from the last frame
		window.clear(Color(30, 30, 40));
		Update(window);
		Render(window);
		// Show everything we just drew
		window.display();
	}
	return 0;
}