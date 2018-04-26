#include "Sensor.h"

Sensor::Sensor(sf::Vector2f position)
{
	body.setPosition(position);
	body.setSize(sf::Vector2f(250.0f,200.0f));
	body.setOrigin(body.getSize() / 2.0f);
}

void Sensor::Update(sf::Vector2f position) 
{

	body.setPosition(position);
	if (checksensorcollision != 0) {
		Hited = true;
	}
	else Hited = false;
}

