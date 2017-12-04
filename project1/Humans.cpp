#include <iostream>
#include "Humans.h"
#include "Creature.h"
using namespace std;

Humans::Humans(int t):Creature(t)
{
	type =t;
}
Humans::~Humans(){}
int Humans::getType()
{
	return type;
}
	
