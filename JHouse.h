#ifndef JHOUSE_H
#define JHOUSE_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class JHouse : public House
{
private:
	std::string description;	
public:
	JHouse(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
	Item* getItem(Char* player);
};

#endif
