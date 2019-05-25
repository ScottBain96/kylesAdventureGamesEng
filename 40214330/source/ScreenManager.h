#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <string>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "MenuScreen.h"
#include "FadeAnimation.h"
#include <SFML/Audio.hpp>

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void initialize();
	void loadContent();
	void unloadContent();
	void update(float dt, sf::Event event);
	void draw(sf::RenderWindow &window);

	void addScreen(GameScreen *screen);
	float getAlpha();

	void setText(std::string text);
	void drawText();

protected:
private:

	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator = (ScreenManager const&);

	std::string text;

	void transition(float dt);
	bool transitionActive;
	FadeAnimation fade;
	GameScreen *newScreen;
};
#endif // !SCREENMANAGER_H