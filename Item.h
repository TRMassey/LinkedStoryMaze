#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item
{
private:
	std::string name;
	std::string description;
	std::string action;
	bool holdable;
	bool key;
public:
	Item();
	Item(std::string n, std::string d, bool h, bool k, std::string a);
	void getAction();
	std::string getName();
	void getDesc();
	bool getHoldable();
	~Item();
};

#endif
