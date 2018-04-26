#include"monsterdetail.h"



bool Monsterdetails::isDead() {
	if (hp <= 0) return true;
	else return false;
}

Monsterdetails::Monsterdetails(float a, float b) {
	hp = a;
	attack = b;
}

void Monsterdetails::beAttack(float playerattack) {
	hp = hp - playerattack;
}

float Monsterdetails::getAttack() {
	return attack;
}