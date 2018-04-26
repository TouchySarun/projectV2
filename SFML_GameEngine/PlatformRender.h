#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class PlatformRender
{
public:
	sf::RectangleShape test;

	PlatformRender(sf::Texture * texture, sf::Vector2f position);
	~PlatformRender();
	void draw(sf::RenderWindow &window);
	sf::RectangleShape * getPosition();
private:
	sf::RectangleShape body;
};