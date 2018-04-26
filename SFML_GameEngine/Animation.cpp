#include "Animation.h"
#include <iostream>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageTile, float* switchTime, unsigned int* imageCount)
{
	this->imageTile = imageTile;
	this->switchTime = switchTime;
	this->imageCount = imageCount;
	totalTime = 0.0f;
	currentImage.x = 0;
	
	uvRect.width = texture->getSize().x / float(imageTile.x);
	uvRect.height = texture->getSize().y / float(imageTile.y);
}

Animation::~Animation()
{
	
}

bool Animation::Update(int row, float deltaTime, bool faceRight, bool keyChange)
{
	currentImage.y = row;
	totalTime += deltaTime;
	
	if (keyChange) currentImage.x = 0;

	if(totalTime >= switchTime[row])
	{
		totalTime -= switchTime[row];
		currentImage.x++;
		//std::cout << " switch " << switchTime[row];
		if (currentImage.x >= *(imageCount+row))
		{
			currentImage.x = 0;
			endSheet = true;
			//std::cout << "endsheet";
		}
		else endSheet = false;

		//std::cout << currentImage.x;
	}
	
	
	uvRect.top =  currentImage.y * uvRect.height;
	
	if(!faceRight)
	{	
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	
	return endSheet;
}
 
