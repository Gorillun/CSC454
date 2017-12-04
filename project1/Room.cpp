#include <iostream>
#include <stdlib.h>
#include "Room.h"
#include "Creature.h"

using namespace std;

Room::Room(int r)
	{
		roomNumber = r;
		state = 0;
		north = 0;
		south = 0;
		east = 0;
		west = 0;
		numOfCreatures = 0;
	}
Room::~Room()
{
	free(creatures);
};
void Room::getRoomData()
{
	cout << "You are in room"<< roomNumber << ".\n";
	int i = 1;
	int cleanliness = state;
	cout << "\nNumOfCreatures "<<numOfCreatures<<endl;
	if(cleanliness == 0)
	{
		cout << "This room is clean";
	}
	else if(cleanliness == 1)
	{
		cout << "This room is half clean.";
	}
	else
	{
		cout << "This room is dirty";
	}

	if(north != -1)
	{
		cout << "\nRoom to the North has " << north <<" occupants.";
	}
	if(south != -1)
	{
		cout << "\nRoom to the South has " << south <<" occupants.";
	}
	if(east != -1)
	{
		cout << "\nRoom to the East has " << east <<" occupants.";
	}
	if(west != -1)
	{
		cout << "\nRoom to the West has " << west <<" occupants.";
	}
	i = 0;
	while(i<numOfCreatures)
	{
		
		int t = creatures[i]->getType();
		int n = creatures[i]->getName();
		
		cout << "\nThis room contains:\n";
		if(t==0)
		{
			cout << "PC\n";
		}
		else if(t==1)
		{
			cout << "animal " << n << "\n";
		}
		else
		{
			cout << "human " << n << "\n";
		}
		++i;
	}

}
void Room::setState(int s)
{
	state = s;
}
void Room::setNorth(int n)
{
	north = n;
}
void Room::setSouth(int s)
{
	south = s;
}
void Room::setEast(int e)
{
	east = e;
}
void Room::setWest(int w)
{
	west = w;
}
void Room::addCreature(Creature *c)
{
	creatures[numOfCreatures] = c;
	++numOfCreatures;
}
void Room::setNumOfCreatures(int n)
		{
			numOfCreatures = n;
		}
int Room::changeRoomCleanliness(int r, int c)
{
	int score = 0;
	int numMoving = 0;
	int moving[10];
	int nc = 0;
	int rm = r;
	int clean = c;

	state = state + c;
	nc = numOfCreatures;
	int i =0;

	while(i<nc)
	{
		int name =creatures[i]->getName();
		int type = creatures[i]->getType();
		if(type == 1)
		{
			if(clean<0)
			{
				cout <<"Animal"<< name <<"licks your face.\n";
				++score;

			}
			else
			{
				cout <<"Animal" << name << "bites your face.\n";
				--score;
				if(state>1)
				{
					if(north >=0)
					{
						cout <<"Animal" << name << "goes North.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(1);
						++numMoving;

					}
					else if(south >=0)
					{
						cout <<"Animal" << name << "goes South.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(2);
						
						++numMoving;

					}
					else if(east >=0)
					{
						cout <<"Animal" << name << "goes East.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(3);
					
						++numMoving;

					}
					else if(west>=0)
					{
						cout <<"Animal" << name << "goes West.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(4);
					
						++numMoving;

					}
					else
					{
						cout <<"Animal" << name << "combusts.\n";
						++numMoving;

					}
				}

			}

		}
		else if(type == 2)
		{
			if(clean>0)
			{
				cout <<"Human" << name << "pats your back.\n";
				++score;

			}
			else
			{
				cout <<"Human" << name << "stabs your face.\n";
				--score;
				if(state>1)
				{
					if(north>=0)
					{
						cout <<"Human" << name << "goes North\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(1);
					
						++numMoving;

					}
					else if(south=0)
					{
						cout <<"Human" << name <<  "goes South.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(2);
					
						++numMoving;

					}
					else if(east>=0)
					{
						cout <<"Human" << name << "goes East.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(3);
					
						++numMoving;

					}
					else if(west>=0)
					{
						cout <<"Human" << name << "goes West.\n";
						moving[numMoving]=i;
						creatures[i]->setRoom(4);
						
						++numMoving;

					}
					else
					{
						cout <<"Human" << name << "combusts.\n";
						++numMoving;

					}
				}
			}

		}


	++i;}

	return score;
}
