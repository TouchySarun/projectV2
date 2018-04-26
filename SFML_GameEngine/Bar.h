#ifndef BAR
#define BAR


#include <SFML\Graphics.hpp>
#include "Animation.h"

class Bar
{
public:
	Bar(sf::Vector2f position, float point, sf::Color color);
	void Update(sf::Vector2f position, float point );
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;

};
#endif


