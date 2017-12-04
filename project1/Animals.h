#include "Creature.h"
#ifndef ANIMALS_H
#define ANIMALS_H

class Animals: public Creature
{
	private:
		int name;
		int room;
		int type;
	public:
	Animals(int t);
	int getType();
	virtual ~Animals();
};
#endif
