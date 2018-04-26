#include <SFML\Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Collider.h"


class Player
{
	public:
		Player(sf::Texture* texture, sf::Vector2u imageCount, float* switchTime, float maxSpeed, unsigned int* Count);
		~Player();
		
		void Update(float deltaTime, int checkPlayerCollision);
		void draw(sf::RenderWindow& window);
		
		std::vector<int> checkPlayerCollision;
		
		sf::Vector2f GetPosition()
		{
			return body.getPosition();
		}
		
		 Collider GetCollider()
		{
			return Collider (body);
		}
	
	private:
		sf::RectangleShape body;
		Animation animation;
		unsigned int row;
		float maxSpeed;
		float speed;
		float velocity;
		bool faceRight;
		bool touchground = false;
		bool check = true;
		bool acttacking = false;
		bool endSheet = false;
		bool keyChange = false;
};
