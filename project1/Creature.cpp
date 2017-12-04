#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(int t)
{
	type =t;
}
void Creature::setName(int n)
	{
		name = n;
	}
void Creature::setRoom(int r)
	{
		r;
	}

int Creature::getType()
{
	return type;
}
Creature::~Creature(){}
