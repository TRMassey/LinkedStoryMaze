#ifndef SEWER_H
#define SEWER_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Sewer : public Room
{
private:
	std::string description;	
public:
	Sewer(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
};

#endif
