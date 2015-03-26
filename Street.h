#ifndef STREET_H
#define STREET_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Street : public Room
{
private:
	std::string description;	
public:
	Street(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
};

#endif
