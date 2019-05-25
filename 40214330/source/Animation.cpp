#include "Animation.h"

Animation::Animation(void)
{

}

Animation::~Animation(void)
{

}

void Animation::loadContent(std::string text, sf::Texture image, sf::Vector2f position)
{
	//"this->" refers to the class variable instead of the parameter
	this->preText = text;
	this->image = image;
	this->position = position;

	alpha = 1.0f;
	textColor = sf::Color(100, 20, 33);
	if (image.getSize().x > 0)
	{

	}
	sprite.setTexture(image);
	this->text.setString(text);
	active = false;
}

void Animation::unloadContent()
{

}

void Animation::draw(sf::RenderWindow &window)
{
	std::string str = text.getString();
	if (str != "")
	{
		window.draw(text);
	}
	if (sprite.getTexture() != NULL)
	{
		window.draw(sprite);
	}
}

float Animation::getAlpha()
{
	return alpha;
}

void Animation::setAlpha(float value)
{
	alpha = value;
}

void Animation::setActive(bool value)
{
	active = value;
}

void Animation::update(sf::RenderWindow &window)
{

}