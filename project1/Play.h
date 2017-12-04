#ifndef PLAY_H
#define PLAY_H
#include "Creature.h"
#include "Room.h"
class Room;
class Play
{
	private:
		Room* rooms[100];
		Creature *creatures[100];
		int numOfRooms;
		int numOfCreatures;

		int currentRoom;
	public:
	int score;
	Play();
	virtual ~Play();
	void help();
	void changeRoom(int c, int r);
	void playGame();
	void initializeWorld();

};
#endif
