#include "Collider.h"
#include <iostream>
Collider::Collider(sf::RectangleShape &body)
{
	this->body = &body;
}
	
Collider::~Collider()
{
		
}
	
int Collider::CheckCollision(Collider other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
		
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
		
	int ch = 0;
		
	if(intersectX < 0.0f && intersectY <0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
			
			
		std::cout<<1;
			
			
		if(intersectX > intersectY)
		{	
			if(deltaX > 0.0f)
			{
					
				ch = 1;
				//Move(intersectX * (1.0f - push), 0.0f);
				//other.Move(-intersectX * push, 0.0f);
			}
				
			else
			{
				ch = 2;
				//Move(-intersectX * (1.0f - push), 0.0f);
				//other.Move(intersectX * push, 0.0f);
			}
				
				
				
		}
			
		else
		{
			if(deltaY > 0.0f)
			{	
				ch = 3;
				//Move(0.0f, intersectY * (1.0f - push));
				//other.Move(0.0f, -intersectY * push);
			}
				
			else
			{
				ch = 4;
				//Move(0.0f, -intersectY * (1.0f - push));
				//other.Move(0.0f, intersectY * push);
			}
		}
		
		
			
			
			
	}
		
	else ch = 0;
		
	return ch;
}
