#include "Monster.h"
#include <stdlib.h>
#include <time.h>

Monster::Monster(sf::Texture * texture, sf::Vector2u imageTile, float *switchTime, float speed, unsigned int* imageCount, sf::Vector2f position)
{
	this->animation = new MonsAnimation(texture, imageTile, switchTime, imageCount);
	//this->position = position;
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(4/1.5*texture->getSize().x / float(imageTile.x), 4 / 1.5*texture->getSize().y / float(imageTile.y)));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);

	faceRight = true;
}

Monster::~Monster()
{

}

void Monster::Update(float deltaTime,int player_position_x)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (checkplayeratkmonster != 0) {
			if (this->GetPosition().x<player_position_x) movement.x -= 200;
			else movement.x += 200;
			//monsdetail->beAttack();

		}
		//switch (checkmonsterplayer)
		//{
		//case 1:
		//	movement.x += 200;
		//	check = false;
		//	break;

		//case 2:
		//	movement.x -= 200;
		//	check = false;
		//	faceRight = false;
		//	break;
		////case 3:
		////	movement.y += 10;
		////	break;
		////case 4:
		////	movement.y -= 10;
		////	break;
		//case 0:
		//	check = true;
		//	break;
		//}

	}
	switch (checkPlayerCollision)
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
		break;
	case 0:
		check = true;
		break;
	}

	// walk
	if (playerwastouch) {
		if (this->GetPosition().x<player_position_x)faceRight = true;
		else faceRight = false;
	}
	else {
		if (rand()%1000 == 5) {
			faceRight = !faceRight;
		}	
	}
	if (body.getPosition().x >= 2670) faceRight = false;
	else if(body.getPosition().x <= -600)faceRight = true;

	if (faceRight)movement.x += 70 * deltaTime;
	else movement.x -= 70 * deltaTime;
	if (checkPlayerCollision == 4 || touchground)
	{
		velocity = 0;
		touchground = true;
	}
	else
	{
		touchground = false;
		velocity += 1000 * deltaTime;
		movement.y += velocity * deltaTime;
	}
	
	row = 0;

	animation->Update(row, deltaTime, faceRight);
	body.setTextureRect(animation->uvRect);
	body.move(movement.x, movement.y);
}

void Monster::draw(sf::RenderWindow & window)
{
	window.draw(body);
}
