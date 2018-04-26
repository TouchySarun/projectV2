#include <SFML\Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"
#include "playerdetail.h"
#include "Monster.h"
#include "Platform.h"
#include "PlatformRender.h"
#include "Bar.h"
#include "Sensor.h"
#include <cstddef>
#include <vector>

static const float VIEW_HEIGHT = 1024.0f;
static const float VIEW_WIDTH = 768.0f;

float aspectRatio = VIEW_HEIGHT / VIEW_WIDTH;
const float mapSize = 1024 * 3;

void ResizeView(const sf::RenderWindow& window, sf::View  view)
{
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int monster_snell_num = 2;

int main()
{
	srand(time(0));
	bool screenMoving = false;
	//renge
	sf::Vector2f attacksensor_player(100.0f,0.0f),hpbar_player(0.0f,150.0f),manabar_player(0.0f,140.0f);

	sf::RenderWindow window(sf::VideoMode(VIEW_HEIGHT, VIEW_WIDTH), "Windows", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT * aspectRatio , VIEW_HEIGHT));
	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("asset/character.png");
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("asset/char.png");
	unsigned int playerVector[7];
	float playerSwitchTime[7];

	// Player details
	//playerTexture[0].loadFromFile("asset/char_stand.png");
	playerVector[0] = 4;
	playerSwitchTime[0] = 0.5f;

	//playerTexture[1].loadFromFile("asset/char_walk.png");
	playerVector[1] = 4;
	playerSwitchTime[1] = 0.15f;

	playerVector[2] = 3;
	playerSwitchTime[2] = 0.15f;

	playerVector[3] = 3;
	playerSwitchTime[3] = 0.15f;

	playerVector[4] = 3;
	playerSwitchTime[4] = 0.15f;

	playerVector[5] = 1;
	playerSwitchTime[5] = 0.f;

	playerVector[6] = 2;
	playerSwitchTime[6] = 0.5f;

	//playerdetail
	Playerdetails* details;
	details = new Playerdetails(100, 100, 10);
	//-------

	Player player(&playerTexture, sf::Vector2u(4, 7), playerSwitchTime, 500.0f, playerVector,details);
	
	Platform platform1(nullptr, sf::Vector2f(mapSize + 2*170, 250.f), sf::Vector2f(mapSize / 2 - 1024 / 2, 405.0f));
	
	

	//Bar
	Bar playerhpbar((player.GetPosition() - hpbar_player), details->getHp(), sf::Color(255, 0, 0));
	Bar playermanabar((player.GetPosition() - manabar_player), details->getMana(), sf::Color(0, 0, 255));
	//Sensor
	Sensor playeratksensor(player.GetPosition()+attacksensor_player);

	// background
	sf::Texture textureBackground;
	textureBackground.loadFromFile("asset/background.png");
	std::vector<PlatformRender> background;

	for (int i = -690; i < 2670 / 2.5; i += 4/1.5 *307)
	{
		PlatformRender *temp;
		temp = new PlatformRender(&textureBackground, sf::Vector2f(float(i), -700.f));
		background.push_back(*temp);
		delete temp;
	}


	// ground
	sf::Texture textureGround;
	textureGround.loadFromFile("asset/ground.png");
	std::vector<PlatformRender> ground;
	
	for (int i = -690; i < 2670; i += 4/1.5* 360)
	{
		PlatformRender *temp;
		temp = new PlatformRender(&textureGround, sf::Vector2f(float(i), 255.f));
		ground.push_back(*temp);
		delete temp;
	}
	
	//Monster
	vector<Monster> monster_snell;
	sf::Texture monster_snellTexture;
	monster_snellTexture.loadFromFile("asset/mon.png");
	unsigned int monsterVector[2];
	float monsterSwitchTime[2];

	monsterVector[0] = 4;
	monsterSwitchTime[0] = 0.3f;
	
	for (int i = 0; i < monster_snell_num;i++) {
		Monster *temp;
		temp = new Monster(&monster_snellTexture, sf::Vector2u(4, 2), monsterSwitchTime, 200.f, monsterVector, sf::Vector2f((2000 * (i + 1))*0.1f, 0.f));
		monster_snell.push_back(*temp);
		delete temp;

	}
	sf::Event evnt;






	float deltaTime = 1.0f;
	//bool checkPlayerCollision;
	sf::Clock clock;
	
	while(window.isOpen())
	{
		
		deltaTime = clock.restart().asSeconds();

		while(window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					printf("New window widht: %i New window height: %i\n", evnt.size.width, evnt.size.height);
					ResizeView(window, view);
					break;
				//case sf::Event::TextEntered:
					//printf("%c", evnt.text.unicode);
					//std::cout << player.GetPosition().x << std::endl;
				
			}
			
		}
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//player.setPosition((float)mousePos.x, (float)(mousePos.y));
		}
		
		
		//printf("%d", player.GetCollider().x);
		player.checkPlayerCollision = platform1.GetCollider().CheckCollision(player.GetCollider(), 0.0f);
		for (int i = 0;i < monster_snell_num;i++) {
			if (0 != player.GetCollider().CheckCollision(monster_snell[i].GetCollider(), 0.0f)) {
				monster_snell[i].playerwastouch = true;
			}
			if (monster_snell[i].checkmonsteratkplayer != 0) {
				details->beAttack(5.0);
			}
			monster_snell[i].checkPlayerCollision = platform1.GetCollider().CheckCollision(monster_snell[i].GetCollider(), 0.0f);
			monster_snell[i].checkplayeratkmonster = playeratksensor.GetCollider().CheckCollision(monster_snell[i].GetCollider(), 0.0f);
			monster_snell[i].checkmonsteratkplayer = player.GetCollider().CheckCollision(monster_snell[i].GetCollider(), 0.0f);
		}
		//std::cout << monster.checkPlayerCollision << std::endl;
		
		// Background Update
	


		if (player.walking && screenMoving)
		{
			for (int i = 0; i < background.size(); i++)
			{
				if (player.faceRight) {
					background[i].getPosition()->move(player.speed / 1.5* deltaTime, 0);
				}
				else {
					background[i].getPosition()->move(-player.speed / 1.5* deltaTime, 0);
				}
			}
		}

		player.Update(deltaTime);
		for (int i = 0;i < monster_snell_num;i++) {

			monster_snell[i].Update(deltaTime, player.GetPosition().x);

		}
		playerhpbar.Update(player.GetPosition() - hpbar_player, details->getHp());
		playermanabar.Update((player.GetPosition() - manabar_player), details->getMana());
		if (player.faceRight) {
			playeratksensor.Update(player.GetPosition() + attacksensor_player);
		}
		else {
			playeratksensor.Update(player.GetPosition() - attacksensor_player);
		}
		//Render position
		if (player.GetPosition().x > 0 && player.GetPosition().x < mapSize - 1024) {
			view.setCenter(player.GetPosition().x, 0);
			screenMoving = true;
		}
		else screenMoving = false;

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);

		for (int i = 0; i < background.size(); i++)
		{
			background[i].draw(window);
		}
		//window.draw(ground);
		for (int i = 0; i < ground.size(); i++)
		{
			ground[i].draw(window);
		}

		//playeratksensor.draw(window);
		for (int i = 0;i < monster_snell_num;i++) {
			monster_snell[i].draw(window);
		}
		player.draw(window);
		playerhpbar.draw(window);
		playermanabar.draw(window);
		//platform1.draw(window);

		
		window.display();
	} 
	
	
	return 0;
}