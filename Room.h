#ifndef ROOM_H
#define ROOM_H
#include "World.h"
#include "Char.h"
#include "Maggie.h"
#include "Joe.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

class Room
{
friend class World;
private:
	std::string name;
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	bool benTo;
	
public:
	Room(std::string type, Room* n, Room* s, Room* e, Room* w);
	Room* addRoom(int direction);
	std::string getName();
	int getDoor(int num, Room* choice);
	void printActions();
	virtual int actions(int num, Room* choice, Char* player, Maggie* npc, Joe* npc2);
	virtual void getDesc() = 0;
	virtual void setDesc() = 0;
	virtual Item* getItem(Char* player);	// See a list of what's in the room and pick the item you want
	virtual void interactItem(Item* pick, Char* player);	// See what you can do with the item
	void setBenTo();
	bool getBenTo();
	Room* add(int direction);
	Room* move(int direction);
	~Room();
};

#endif
