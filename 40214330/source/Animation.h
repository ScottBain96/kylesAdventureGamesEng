#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(void);
	~Animation(void);

	virtual void loadContent(std::string text, sf::Texture image, sf::Vector2f position);
	virtual void unloadContent();
	virtual void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	virtual void setAlpha(float value);
	float getAlpha();
	void setActive(bool value);

protected:
	float alpha;
	std::string preText;
	sf::Text text;
	sf::Texture image;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Color textColor;
	sf::IntRect sourceRect;
	bool active;
private:
};
#endif // !ANIMATION_H