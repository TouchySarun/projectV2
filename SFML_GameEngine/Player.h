#ifndef PLAYER
#define PLAYER

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "playerdetail.h"

class Player
{
	public:
		Player(sf::Texture* texture, sf::Vector2u imageCount, float* switchTime, float maxSpeed, unsigned int* Count, Playerdetails * details);
		~Player();

		void Update(float deltaTime);
		void draw(sf::RenderWindow& window);
		
		int checkPlayerCollision;
		
		sf::Vector2f GetPosition()
		{
			rectPlayer.setPosition(body.getPosition());
			return body.getPosition(), rectPlayer.getPosition();
		}
		
		 Collider GetCollider()
		{
			return Collider (body);
		}
		
		bool acttacking = false;
		bool walking = false;
		bool faceRight = true;
		float speed;
	
	private:

		Playerdetails * details;
		sf::RectangleShape body;
		sf::RectangleShape rectPlayer;
		Animation * animation;
		unsigned int row;
		float maxSpeed;
		float velocity;
		bool touchground = false;
		bool check = true;
		bool endSheet = false;
		bool keyChange = false;
		bool death = false;
		

		int stepAtk;
		float totalTime = 0.f;
};
#endif