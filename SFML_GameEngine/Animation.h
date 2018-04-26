#ifndef ANIMATION
#define ANIMATION
#include <SFML\Graphics.hpp>

class Animation
{
	public:
		Animation(sf::Texture* texture, sf::Vector2u imageTile, float* switchTime, unsigned int* imageCount);
		~Animation();
		
		bool Update(int row, float deltaTime, bool faceRight, bool keyChange);
		
		sf::IntRect uvRect;
		
	private:
		 sf::Vector2u imageTile;
		 sf::Vector2u currentImage;
		 
		 unsigned int* imageCount;
		 float totalTime;
		 float* switchTime;
		 bool endSheet = false;
};

#endif
