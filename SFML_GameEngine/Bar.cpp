#include"Bar.h"

Bar::Bar(sf::Vector2f position, float point, sf::Color color) {
	body.setSize(sf::Vector2f(point * 2.0f, 10.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(color);
}

void Bar::Update(sf::Vector2f position, float point) {
	if (point <= 0)point = 0;
	body.setSize(sf::Vector2f(point * 2.0f, 10.0f));
	body.setPosition(position);
}

void Bar::draw(sf::RenderWindow& window) {
	window.draw(body);
}
