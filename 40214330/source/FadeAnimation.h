#ifndef FADEANIMATION_H
#define FADEANIMATION_H
#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	FadeAnimation(void);
	~FadeAnimation(void);

	void loadContent(std::string text, sf::Texture image, sf::Vector2f position);
	virtual void unloadContent();
	virtual void update(float dt);
	void draw(sf::RenderWindow &window);

	void setAlpha(float value);

protected:
private:
	bool increase;
	float fadeSpeed;
	float dt;
};
#endif // !FADEANIMATION_H