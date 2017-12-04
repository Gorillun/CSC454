#include "Creature.h"
#ifndef HUMANS_H
#define HUMANS_H

class Humans: public Creature
{
	private:
		int name;
		int room;
		int type;
	public:
	Humans(int t);
	virtual ~Humans();
	int getType();
};
#endif
