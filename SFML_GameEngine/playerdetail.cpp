#include "playerdetail.h"


bool Playerdetails::isDead() {
	if (hp <= 0) return true;
	else return false;
}

Playerdetails::Playerdetails(float a, float b, float c) {
	hp = a;
	mana = b;
	attack = c;
}

void Playerdetails::beAttack(float monattack) {
	hp = hp - monattack;
}

void Playerdetails::heal(float hpheal) {
	hp = hp + hpheal;
}

void Playerdetails::usemana(float usedmana) {
	mana = mana - usedmana;
}

void Playerdetails::addmana(float newmana) {
	mana = mana + newmana;
}


float Playerdetails::getAttack() {
	return attack;
}

float Playerdetails::getHp() {
	return hp;
}

float Playerdetails::getMana() {
	return mana;
}