#include <SFML\Graphics.hpp>
#include "Collider.h"

class Platform
{
	public:
		Platform(sf::Texture *texture, sf::Vector2f Size, sf::Vector2f Position);
		~Platform();
		
		void draw(sf::RenderWindow& window);
		Collider GetCollider(){return Collider(body);}
		
	private:
		sf::RectangleShape body;	
};
