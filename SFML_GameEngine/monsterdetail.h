#include<iostream>
using namespace std;

class Monsterdetails{
	private:
	float hp;
	float attack;
	public:
		bool isDead();
		Monsterdetails(float,float);
		void beAttack (float);
		float getAttack();
};


