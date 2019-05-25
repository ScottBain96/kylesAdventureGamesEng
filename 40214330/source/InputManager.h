#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <SFML\Window.hpp>

//Handles our keyboard inputs
class InputManager
{
public:
	InputManager();
	~InputManager();

	void update(sf::Event event);

	bool keyPressed(sf::Keyboard::Key key);
	bool keyReleased(sf::Keyboard::Key key);
	bool keyPressed(std::vector<sf::Keyboard::Key> keys);
	bool keyReleased(std::vector<sf::Keyboard::Key> keys);
	const sf::Keyboard::Key options[7] =
	{
		sf::Keyboard::Num1,
		sf::Keyboard::Num2,
		sf::Keyboard::Num3,
		sf::Keyboard::Num4,
		sf::Keyboard::Num5,
		sf::Keyboard::Num6,
		sf::Keyboard::Escape
	};
	const sf::Keyboard::Key controls[4] =
	{
		sf::Keyboard::A, //Player Left
		sf::Keyboard::D, //Player Right
		sf::Keyboard::Space, //Player Jump
		sf::Keyboard::R, //Player Boost
	};
protected:
private:
	sf::Event event;
};

#endif // !INPUTMANAGER_H
