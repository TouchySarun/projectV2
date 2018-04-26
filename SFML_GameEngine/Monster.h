#include <SFML\Graphics.hpp>
#include "MonsAnimation.h"
#include "monsterdetail.h"
#include "Collider.h"

class Monster
{
public:
	Monsterdetails * monsdetail;

	Monster(sf::Texture* texture, sf::Vector2u imageTile, float *switchTime, float speed, unsigned int* imageCount, sf::Vector2f position);
	~Monster();

	void Update(float deltaTime,int player_position_x);
	void draw(sf::RenderWindow& window);

	int checkPlayerCollision;
	int checkplayeratkmonster;
	int checkmonsteratkplayer;

	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}

	Collider GetCollider()
	{
		return Collider(body);
	}
	bool playerwastouch = false;

private:
	sf::RectangleShape body;
	MonsAnimation * animation;
	//sf::Vector2f position;

	unsigned int row;
	float speed;
	bool faceRight;
	bool check;
	bool touchground = false;
	float velocity;
	bool turn = true;

};
