#ifndef SECRET_H
#define SECRET_H
#include "Room.h"
#include "Item.h"
#include "Char.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

class Secret : public Room
{
private:
	std::string description;	
public:
	Secret(std::string t, Room* n, Room* s, Room* e, Room* w);
	void setDesc();
	void getDesc();
	int actions(int num, Room* choice);
};

#endif
