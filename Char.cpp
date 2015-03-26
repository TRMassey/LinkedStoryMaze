#include "Char.h"
#include "Item.h"
#include "World.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>


/**************************************************************
 * Char::Char : Character()
 * Purpose: Default Constructor
 * Entry: None
 * Exit: Creates a non-specific character
 * ************************************************************/
Char::Char(){
	this->name = "none";
	this->description = "none";
	this->HP = 0;
	this->doorChoice = 0;
	this->location = "none";
	this->keys = false;
	this->lost = false;}


/**************************************************************
 * Char::Char : Character(std::string n, std::string d)
 * Purpose: Constructor
 * Entry: Name and description
 * Exit: Creates a new starting character for the player
 * ************************************************************/
Char::Char(std::string n, std::string d){
	this->name = n;
	this->description = d;
	this->HP = 10;
	this->doorChoice = 0;
	this->location = "here";
	this->keys = false;
	this->lost = false;}


/**************************************************************
 * Char::~Char : Character()
 * Purpose: Deconstructor
 * Entry: None
 * Exit: Deconstruction of Char class
 * ************************************************************/
Char::~Char(){}


/*****************************************************************
 * std::string Char::getName()
 * Purpose: returns the character's name
 * Entry: None
 * Exit: Returns the character's name
 * ****************************************************************/
std::string Char::getName(){
	return name;}


/****************************************************************
 * std::string Char::getDesc()
 * Purpose: Returns the character's description
 * Entry: None
 * Exit: Returns the character's description
 * *************************************************************/
std::string Char::getDesc(){
	return description;}


/**************************************************************
 * void Char::setHP(int)
 * Purpose: Changes the health of the character if a trap is
 * triggered
 * Entry: Integer to subract from health
 * Exit: Changed HP amount for player
 * ************************************************************/
void Char::setHP(int num){
	HP = HP - num;}


/***************************************************************
 * int Char::getHP()
 * Purpose: Prints current health of player
 * Entry: None
 * Exit: Returns health of player
 * ***********************************************************/
int Char::getHP(){
	return HP;}


/***************************************************************
 * bool Char::getKeys()
 * Purpose: Determines if the character has all needed items to
 * finish
 * Entry: None
 * Exit: Returns True if can exit, false otehrwise
 * ***********************************************************/
bool Char::getKeys(){
	return keys;}


/**************************************************************
 * void Char::setKeys()
 * Purpose: Changes keys to true if the character haas all needed
 * items
 * Entry: None
 * Exit: Keys if false if not all items found, true if all are
 * found
 * ***********************************************************/
void Char::setKeys(){
	int amount = 0;

	for(int i = 0; i < bag.size(); i++){
		if(bag[i]->getName() == "Hair pins" || bag[i]->getName() == "Booze" || bag[i]->getName() == "Metal" || bag[i]->getName() == "Pantyhose")
			amount = amount + 1;
		if(amount == 4)
			keys = true;}}



/***************************************************************
 * bool Char::getLost()
 * Purpose: Returns if the character has lost
 * Entry: None
 * Exit: Returns True if the player has lost, false otherwise
 * ***********************************************************/
bool Char::getLost(){
	return lost;}


/**************************************************************
 * void Char::setLost()
 * Purpose: Changes lost to true if the character has run out
 * of health or time
 * Entry: None
 * Exit: Changes lost to true if the player has met losing 
 * conditions
 * ***********************************************************/
void Char::setLost(){
	lost = true;}


/***************************************************************
 * void Char::addToBag(Item*)
 * Purpose: Allows the character to pick up an item
 * Entry: Pointer to item character wants to pick up and store
 * Exit: Bag is one item more
 * ************************************************************/
void Char::addItem(Item* thing){
	if(bag.size() < 8){
		bag.push_back(thing);
		std::cout << std::string(50, '\n');
		std::cout << "You tuck away the " << thing->getName() << " . Never know when it will come in handy, right?" << std::endl;}
	else{
		std::cout << std::string(50, '\n');
		std::cout << "Your pack is literally bulging at the seams. Are you a tailor? Didn't think so. Best not push your luck.";
		std::cout << "\nYou, unfortunately, have to put the item back.";}}
	

/*******************************************************************
 * void Char::setLocation(std::string input)
 * Purpose: Sets the loction the character is currently in
 * Entry: Current Room
 * Exit: Saves the character's current location to location
 * *****************************************************************/
void Char::setLocation(std::string input){
	location = input;}


/*******************************************************************
 * std::string Char::getLocation()
 * Purpose: Returns the loction the character is currently in
 * Entry: None
 * Exit: Prints the location the character is currently in
 * *****************************************************************/
std::string Char::getLocation(){
	return location;}	



/***************************************************************
 * void Char::viewBag()
 * Purpose: Allows the player to look in their bag
 * Entry: None
 * Exit: Prints what the player has elected to put in the 
 * character's bag
 * ************************************************************/
void Char::viewBag(){
	if(bag.size() == 0)
		std::cout << "Your bag is pitifully empty at the moment." << std::endl;
	else{
		std::cout << "You have the following items crammed into your bag: " << std::endl;;
		for(int i = 0; i < bag.size(); i++)
			std::cout << bag[i]->getName() << std::endl;}}



/***************************************************************
 * int Char::converesation(Char* other)
 * Purpose: Prints NPC specific conversation lines
 * Entry: NPC the player is talking to
 * Exit: Returns an integer that is the conversation choice
 * ************************************************************/
int Char::conversation(Char* other){
	int num;
	std::string input;

	if(other->getName() == "Maggie"){
		std::cout << "\nWhat on earth do you say now..: " << std::endl;
		std::cout << "\n1. Hi, Marcy was it? Annie? M..M.. Maggie?" << std::endl;
		std::cout << "2. Darling! So good to see you again. Don't mind that I dropped by, do you?" << std::endl;
		std::cout << "3. Ah, hells." << std::endl;
			
		std::cout << "Your best bet: ";
		std::getline(std::cin, input);
		num = atoi(input.c_str());
		return num;}

	if(other->getName() == "Joe"){
		std::cout << "\nBest be friendly..: " << std::endl;
		std::cout << "\n1. Cra-- err.. Joe! Joe? How ya been, buddy? " << std::endl;
		std::cout << "2. Shhhh... this is just a dream..." << std::endl;
		std::cout << "3. Screw this, you're knocking him out. He left you with the tab at the pub last week." << std::endl;
	
		std::cout << "Your best interpretation of being friendly: ";
		std::getline(std::cin, input);
		num = atoi(input.c_str());
		return num;}}
