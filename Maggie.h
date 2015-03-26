#ifndef MAGGIE_H
#define MAGGIE_H
#include "Char.h"
#include <iostream>
#include <string>

class Maggie : public Char
{
private:
	std::string name;
	std::string description;
	bool talkTwice;
public:
	Maggie();
	std::string getName();
	void getDescription();
	void setTalkTwice();
	bool getTalkTwice();
	int conversation(int num);
	void talkedTwice();
};

#endif
