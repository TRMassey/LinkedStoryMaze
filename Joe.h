#ifndef JOE_H
#define JOE_H
#include "Char.h"
#include <iostream>
#include <string>

class Joe : public Char
{
private:
	std::string name;
	std::string description;
	bool talkTwice;
public:
	Joe();
	std::string getName();
	void getDescription();
	void setTalkTwice();
	bool getTalkTwice();
	int conversation(int num);
	void talkedTwice();
};

#endif
