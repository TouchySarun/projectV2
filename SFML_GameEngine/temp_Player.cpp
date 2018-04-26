#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageTile, float* switchTime, float maxSpeed ,unsigned int* imageCount):
	animation(texture, imageTile, switchTime, imageCount)
{
	this->maxSpeed = maxSpeed;
	row = 0;
	faceRight = true;
	std::cout << texture->getSize().x << " " << texture->getSize().y << std::endl;

	body.setSize(sf::Vector2f(4/1.5*texture->getSize().x / float(imageTile.x) ,4/1.5*texture->getSize().y / float(imageTile.y)));
	std::cout << 3 * texture->getSize().x / float(imageTile.x) << " " << 3 * texture->getSize().y / float(imageTile.y);
	body.setOrigin(body.getSize()/2.f); 
	body.setPosition(0.0f, 0.0f);
	body.setTexture(texture);
}

Player::~Player()
{
	
}

void Player::Update(float deltaTime, int checkPlayerCollision)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	switch(checkPlayerCollision)
	{
		case 1:
			movement.x += 10;
			check = false;
			break;
				
		case 2:
			movement.x -= 10;
			check = false;
			faceRight = false;
			break;
		case 3:
			movement.y += 10;
			break;
		case 4:
			movement.y -= 10;
			std::cout << "2";
			break;
		case 0:
			check = true;
			break;
	}

	if (checkPlayerCollision == 4 || touchground) 
	{
		velocity = 0;
		touchground = true;
	}
	else
	{
		touchground = false;
		velocity += 10;
		movement.y += velocity * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
	{
		if(speed <= maxSpeed) speed += 5;
	}
	else
	{
		speed = 0;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= speed * deltaTime;
		//std::cout<<movement.x;
	}
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += speed * deltaTime;
				
	}
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= 1500 * deltaTime;
		touchground = false;
	}
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += speed * deltaTime;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !acttacking) {
		row = 2;
		acttacking = true;
		keyChange = true;
	}else keyChange = false;

	if (acttacking)
	{
		if (endSheet) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			{
				if (row == 2) row = 3;
				else if (row == 3) row = 4;
				else if (row == 4) row = 2;
			}
			else acttacking = false;
		}
	}

	if(movement.x == 0.0f && !acttacking)
	{
		row = 0;
	}

	if (movement.x != 0.0f && !acttacking)
	{
			
		row = 1;
			
		if(movement.x > 0.0f && check == true)
		{
			faceRight = true;
				
		}
			
		else faceRight = false;
	}
		
	endSheet = animation.Update(row, deltaTime, faceRight, keyChange);
	body.setTextureRect(animation.uvRect);
		
	body.move(movement.x, movement.y);
		
		
}

void Player::draw(sf::RenderWindow& window )
{
	window.draw(body);
}
