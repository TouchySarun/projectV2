#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageTile, float* switchTime, float maxSpeed ,unsigned int* imageCount,Playerdetails *details)
{
	this->details = details;
	this->animation = new Animation(texture, imageTile, switchTime, imageCount);
	this->maxSpeed = maxSpeed;
	row = 0;
	faceRight = true;
	std::cout << texture->getSize().x << " " << texture->getSize().y << std::endl;

	rectPlayer.setSize(sf::Vector2f(4 / 1.5*texture->getSize().x / float(imageTile.x), 4 / 1.5*texture->getSize().y / float(imageTile.y)));
	rectPlayer.setOrigin(rectPlayer.getSize() / 2.f);
	rectPlayer.setPosition(sf::Vector2f(body.getSize().x / 2.f, body.getSize().y / 2.f));
	rectPlayer.setTexture(texture);

	body.setSize(sf::Vector2f(40.0f*4/1.5, 60.0f*4/1.5-20));
	std::cout << 3 * texture->getSize().x / float(imageTile.x) << " " << 3 * texture->getSize().y / float(imageTile.y);
	body.setOrigin(body.getSize() / 2.f);
	body.setPosition(0.f,0.f);
	body.setTexture(nullptr);


}

Player::~Player()
{
	
}




void Player::Update(float deltaTime)
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
		velocity += 3000 * deltaTime;
		movement.y += velocity * deltaTime;
	}

	if ( walking )
	{
		if(speed <= maxSpeed) speed += 5;
	}
	else
	{
		speed = 0;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(body.getPosition().x >= -620)
			movement.x -= speed * deltaTime;
		walking = true;
		//std::cout<<movement.x;
	}
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (body.getPosition().x <= 2670)
			movement.x += speed * deltaTime;
		walking = true;		
	}

	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		walking = false;
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || !touchground)
	{
		movement.y -= 1500 * deltaTime;
		touchground = false;
	}
	
	// death simulate
	if(details->isDead())
	{
		row = 6;
		death = true;
		keyChange = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << body.getPosition().x << std::endl;
	}
	
	if (!touchground) row = 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !acttacking && !death) {
		if (stepAtk == 0)
		{
			row = 2;
			stepAtk = 1;
			//std::cout << "atk1 ";
			acttacking = true;
			keyChange = true;
		}
		else if (stepAtk == 1)
		{
			row = 3;
			stepAtk = 2;
			//std::cout << "atk2 ";
			acttacking = true;
			keyChange = true;
		}
		else if (stepAtk == 2)
		{
			row = 4;
			stepAtk = 3;
			//std::cout << "atk3 ";
			acttacking = true;
			keyChange = true;
		}
		else if (stepAtk == 3)
		{
			stepAtk = 0;
		}
	}else keyChange = false;

	totalTime += deltaTime;
	if (totalTime >= 2)
	{
		totalTime -= 2;
		stepAtk = 0;
		//std::cout << "StepChange";
	}
	if (endSheet) acttacking = false;
	
	if (!walking && !acttacking && !death && touchground)
	{
		row = 0;
	}
	if (walking && !acttacking && !death && touchground)
	{
		row = 1;
	}

	if (movement.x > 0.0f && check) faceRight = true;
	if (movement.x < 0.f && check) faceRight = false;

	endSheet = animation->Update(row, deltaTime, faceRight, keyChange);
	rectPlayer.setTextureRect(animation->uvRect);
		
	body.move(movement.x, movement.y);
		
}

void Player::draw(sf::RenderWindow& window )
{
	window.draw(rectPlayer);
	//window.draw(body);
	
}

