#ifndef WORLD_H
#define WORLD_H
#include "Room.h"
#include "Char.h"
#include "Item.h"
#include "Start.h"
#include<iostream>
#include<string>
#include<vector>

class World
{
private:
	Room* start;
	Room* end;
	Room* sewer;
	Room* sewer2;
	Room* secret;
	Room* dead;
	Room* house;
	Room* jHouse;
	Room* street;
	Room* street2;
	Room* final;
	std::vector<Room*> rooms;
	std::vector<Room*> roomsTwo;
	int time;
public:
	World();
	void createWorld();
	void viewWorld();
	void addPath(Room* current);
	void viewPath();
	Room* startPnt();
	void timer(Char* player);
	~World();
};

#endif
