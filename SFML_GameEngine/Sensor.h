#ifndef SENSOR
#define SENSOR
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Sensor {
public:
	bool Hited = false;

	Sensor(sf::Vector2f position);
	void Update(sf::Vector2f position);

	void draw(sf::RenderWindow &window)
	{
		window.draw(body);
	}
	int checksensorcollision;

	Collider GetCollider()
	{
		return Collider(body);
	}



private:
	sf::RectangleShape body;
};
#endif