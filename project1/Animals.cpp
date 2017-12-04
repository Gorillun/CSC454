#include <iostream>
#include "Animals.h"

using namespace std;

Animals::Animals(int t):Creature(t)
{
	type=t;
}
Animals::~Animals(){}
int Animals::getType()
{
	return type;
}
	
