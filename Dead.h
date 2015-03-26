#ifndef DEAD_H
#define DEAD_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "Maggie.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Dead : public Room
{
private:
	std::string description;	
public:
	Dead(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
	Item* getItem(Char* player);
};

#endif
