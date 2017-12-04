#ifndef ROOM_H
#define ROOM_H
#include "Creature.h"
#include "Play.h"
class Room
{
	private:
		int roomNumber;
		int state;
		int north;
		int south;
		int east;
		int west;
		Creature *creatures[10];
		int numOfCreatures;
	public:
	Room(int r);
	virtual ~Room();
	void getRoomData();
	int getNumberOfCreatures(){return numOfCreatures;}
	int getState(){return state;}
	int getNorth(){return north;}
	int getSouth(){return south;}
	int getEast(){return east;}
	int getWest(){return west;}
	void setNumOfCreatures(int);
	void setState(int);
	void setNorth(int);
	void setSouth(int);
	void setEast(int);
	void setWest(int);
	void addCreature(Creature*);
	int changeRoomCleanliness(int, int);

};
#endif
