#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
{

}

FadeAnimation::~FadeAnimation()
{

}

void FadeAnimation::loadContent(std::string text, sf::Texture image, sf::Vector2f position)
{
	Animation::loadContent(text, image, position);
	increase = false;
	fadeSpeed = 1.0f;
}

void FadeAnimation::unloadContent()
{

}

void FadeAnimation::update(float dt)
{
	
	if (active)
	{
		if (!increase)
		{
			alpha -= dt * fadeSpeed;
		}
		else
			alpha += dt * fadeSpeed;

		if (alpha >= 1.0f)
		{
			alpha = 1.0f;
			increase = false;
		}
		else if (alpha <= 0.0f)
		{
			alpha = 0.0f;
			increase = true;
		}
	}
	else
	{
		alpha = 1.0f;
	}
}

void FadeAnimation::setAlpha(float value)
{
	alpha = value;

	if (alpha == 0.0f)
	{
		increase = true;
	}
	else
	{
		increase = false;
	}
}