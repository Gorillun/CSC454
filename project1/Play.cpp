#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <cstddef>
#include "Room.h"
#include "Play.h"
#include "Creature.h"
#include "Animals.h"
#include "Humans.h"

using namespace std;

	Play::Play()
	{
		score = 40;
		numOfRooms = 0;
		numOfCreatures =0;
		currentRoom =0;
		creatures[100] = {NULL};
		rooms[100] = {NULL};
	}
	Play::~Play()
	{
		free(creatures);
		free(rooms);
	}
	void Play::help()
	{
	cout << "\nexit: ends the current game";
	cout << "\neast,west,north,south: directions player can move if possible";
	cout << "\nclean: cleans current room from dirty or half dirty";
	cout << "\n#:clean: cleans a specific room by its number";
	cout << "\nlook: gives information about current room";
	}
	void Play::changeRoom(int c, int r)
	{
	int nc = 0;
	int lr = 0;
	if(c == 0)
	{
		currentRoom = r;
	}
	lr=creatures[c]->getRoom();
	creatures[c]->setRoom(r);
	nc = rooms[lr]->getNumberOfCreatures();
	rooms[lr]->setNumOfCreatures(nc -1);
	nc = 0;
	nc = rooms[r]->getNumberOfCreatures();
	rooms[r]->setNumOfCreatures(nc +1);
	}
/////////////////////////////////////
/////////////////////////////////////
	void Play::playGame()
	{
	char move[10]={NULL};
	while(strcmp(move,"exit")!=0)
	{
		cin >> move;
		if(strcmp(move,"look") == 0)
		{
			rooms[currentRoom]->getRoomData();
			
		}
		else if(strcmp(move,"help") == 0)
		{
			help();
		}
		else if(strcmp(move,"east") == 0)
		{
			changeRoom(0,rooms[currentRoom]->getEast());
		}
		else if(strcmp(move,"west") == 0)
		{
			changeRoom(0,rooms[currentRoom]->getWest());
		}
		else if(strcmp(move,"north") == 0)
		{
			changeRoom(0,rooms[currentRoom]->getNorth());
		}
		else if(strcmp(move,"south") == 0)
		{
			changeRoom(0,rooms[currentRoom]->getSouth());
		}
		else if(strcmp(move,"clean") == 0)
		{
			rooms[currentRoom]->changeRoomCleanliness(currentRoom, 1);
			
		}
		else if(strcmp(move,"dirty") == 0)
		{
			rooms[currentRoom]->changeRoomCleanliness(currentRoom, -1);
			
		}
		else if(strcmp(move,"exit") == 0)
		{
			exit(0);
		}
		else
		{
			char n[4];
			char d[10];
			int s = 0;
			int t = 0;
			int c = 0;
			int l = strlen(move);
			while(move[s] != ':')
			{
				n[s] = move[s];
				++s;
			}
			++s;
			while(s<l)
			{
				d[t] = move[s];
				++t;
				++s;
			}
			s = 0;
			s = atoi(n);
			if(strcmp(d,"clean") == 0)
			{
				c = 1;
			}
			else
			{
				c = -1;
			}
			rooms[s]->changeRoomCleanliness(s,c);
			
		
		}

	}
	}
	void Play::initializeWorld()
	{
	int r=0;
	cin >> r;
	numOfRooms = r;
	r = 0;
	while(r<numOfRooms)
	{
		int state=0;
		int n = 0;
		int s = 0;
		int e = 0;
		int w = 0;
		//an array of pointers to room array
		cin >> state >> n >> s >> e >> w;
		rooms[r] = new Room(r);
		rooms[r]->setState(state);
		rooms[r]->setNorth(n);
		rooms[r]->setSouth(s);
		rooms[r]->setEast(e);
		rooms[r]->setWest(w);
		++r;

	}
	
	r=0;
	cin >> numOfCreatures;
	while(r<numOfCreatures)
	{
		int t = -1;
		int rm = -1;
		int nOc = 0;
		cin >> t >> rm;
		if(t==0)
		{
			currentRoom = rm;
			creatures[r] = new Creature(0);
			creatures[r]->setName(r);
			creatures[r]->setRoom(rm);
			rooms[rm]->addCreature(creatures[r]);
			
			

		}
		else if(t==1)
		{
			creatures[r] = new Animals(1);
			creatures[r]->setName(r);
			creatures[r]->setRoom(rm);
			rooms[rm]->addCreature(creatures[r]);
			
			

		}
		else
		{
			creatures[r] = new Humans(2);
			creatures[r]->setName(r);
			creatures[r]->setRoom(rm);
			rooms[rm]->addCreature(creatures[r]);
	
		
		}


		++r;
	}
	
	playGame();
	}
