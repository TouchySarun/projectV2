#pragma once
#include <SFML\Graphics.hpp>

class MonsAnimation
{
public:
	MonsAnimation(sf::Texture* texture, sf::Vector2u imageTile, float* switchTime, unsigned int* imageCount);
	~MonsAnimation();

	bool Update(int row, float deltaTime, bool faceRight);

	sf::IntRect uvRect;

private:
	sf::Vector2u imageTile;
	sf::Vector2u currentImage;

	unsigned int* imageCount;
	float totalTime;
	float* switchTime;
	bool endSheet = false;
};