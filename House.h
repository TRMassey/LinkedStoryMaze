#ifndef HOUSE_H
#define HOUSE_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "Maggie.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class House : public Room
{
private:
	std::string description;	
public:
	House(std::string t, Room* n, Room* s, Room* e, Room* w);
	virtual void setDesc();
	virtual void getDesc();
	virtual Item* getItem(Char* player);
};

#endif
