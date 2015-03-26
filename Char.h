#ifndef CHAR_H
#define CHAR_H
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

class Char
{
private:
	std::string name;
	std::string description;
	std::vector<Item*> bag;
	int HP;
	int doorChoice;
	std::string location;
	bool keys;
	bool lost;

public:
	Char();
	Char(std::string, std::string d);
	virtual std::string getName();
	virtual std::string getDesc();
	void setHP(int);
	int getHP();
	void setKeys();
	bool getKeys();
	void setLost();
	bool getLost();
	void addItem(Item* thing);
	void viewBag();
	void setLocation(std::string input);
	std::string getLocation();
	virtual int conversation(Char* other);
	~Char();
};

#endif
