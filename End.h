#ifndef END_H
#define END_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class End : public Room
{
private:
	std::string description;	
public:
	End(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
};

#endif
