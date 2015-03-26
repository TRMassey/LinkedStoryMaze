#ifndef START_H
#define START_H
#include "Room.h"
#include "Item.h"
#include "Sewer.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Start : public Room
{
private:
	std::string description;	
public:
	Start(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
	Item* getItem(Char* player);
};

#endif
