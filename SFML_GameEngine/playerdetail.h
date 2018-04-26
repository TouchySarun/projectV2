#ifndef PLAYERDETAIL
#define PLAYERDETAIL

#include<iostream>
using namespace std;

class Playerdetails {
	private:
		float hp;
		float mana;
		float attack;
	public:
		bool isDead();
		Playerdetails(float,float,float);
		void beAttack (float);
		void heal(float);
		void usemana(float);
		void addmana(float);
		float getAttack();
		float getHp();
		float getMana();
};


#endif
