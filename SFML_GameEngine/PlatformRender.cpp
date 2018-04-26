#include "PlatformRender.h"

PlatformRender::PlatformRender(sf::Texture * texture, sf::Vector2f position)
{
	body.setTexture(texture);
	body.setPosition(position);
	body.setSize(sf::Vector2f(4 / 1.5*texture->getSize().x, 4 / 1.5*texture->getSize().y));
}

PlatformRender::~PlatformRender()
{
}

void PlatformRender::draw(sf::RenderWindow &window)
{
	window.draw(body);
}

sf::RectangleShape * PlatformRender::getPosition()
{
	return &body;
}
