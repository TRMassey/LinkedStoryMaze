#ifndef FINAL_H
#define FINAL_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Final : public Room
{
private:
	std::string description;	
public:
	Final(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
	Item* getItems();
	virtual void interactItem(Item* pick, Char* player);
};

#endif
