#ifndef CREATURE_H
#define CREATURE_H
#include<stdio.h>

using namespace std;
class Creature
{
	private:
		int name;
		int room;
		int type;
	public:
	Creature(int);
	virtual ~Creature();
	void setName(int n);
	void setRoom(int r);
	int getName()
	{
		return name;
	}
	int getRoom()
	{
		return room;
	}
	virtual int getType();
};
#endif
