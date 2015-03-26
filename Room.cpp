#include "World.h"
#include "Room.h"
#include "Char.h"
#include "Maggie.h"
#include "Item.h"
#include "Start.h"
#include "Sewer.h"
#include "Secret.h"
#include "Dead.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

/******************************************************************
 * Room::Room(std::string type, Room* n, Room* s, Room * e, Room* w)
 * Purpose: Constructor
 * Entry: Pointer to each door
 * Exit: New Room created
 * ***************************************************************/
Room::Room(std::string type, Room* n, Room* s, Room* e, Room* w){
	this->name = type;
	this->north = n;
	this->south = s;
	this->east = e;
	this->west = w;
	this->benTo = false;}

/******************************************************************
 * Room::~Room()
 * Purpose: Deconstructor
 * Entry: None
 * Exit: Deletes all pointers in room, deconstructs Room class
 * ***************************************************************/
Room::~Room(){
	delete north;
	delete south;
	delete east;
	delete west;}


/******************************************************************
 * std::string getName()
 * Purpose: Get the name of the room
 * Entry: None
 * Exit: Returns the room type
 * ***************************************************************/
std::string Room::getName(){
	return name;}



/******************************************************************
 * void Room::setBenTo()
 * Purpose: set the bool BenTo
 * Entry: None
 * Exit: Sets to true if already having been in start
 * ***************************************************************/
void Room::setBenTo(){
	benTo = true;}


/******************************************************************
 * std::string getBenTo()
 * Purpose: Returns benTo
 * Entry: None
 * Exit: Returns true if already having visited the area
 * ***************************************************************/
bool Room::getBenTo(){
	return benTo;}


/*****************************************************************
 * Room* getDoor(int num)
 * Purpose: Pointer selected for creating a new room
 * Entry: Number selection of travel from user
 * Exit: Returns a new room to be created based off travel direction
 * ****************************************************************/
int Room::getDoor(int num, Room* choice){
	
	if(num == 1){
		if(choice->north == NULL){
			std::cout << "No passage found.." << std::endl;
			num = 5;
			return num;}
		else
			return num;}
	if(num == 2){	
		if(choice->south == NULL){
			std::cout << "No passage found.." << std::endl;
			num = 5;
			return num;}
		else
			return num;}
	if(num == 3){	
		if(choice->east == NULL){
			std::cout << "No passage found.." << std::endl;
			num = 5;
			return num;}
		else{
			num = 3;
			return num;}}
	if(num == 4){	
		if(choice->west == NULL){
			std::cout << "No passage found.." << std::endl;
			num = 5;
			return num;}
		else
			return num;}}


/******************************************************************
 * void Room::printActions();
 * Purpose: Prints the possible actions available to the user
 * Entry: None
 * Exit: Prints possible actions to the screen
 * ***************************************************************/		
void Room::printActions(){
	std::cout << "\n1. Look for someone to talk to";
	std::cout << "\n2. Examine the environment further";
	std::cout << "\n3. Hurry and try to leave this space";
	std::cout << "\n4. I give up. Tell me what to find and do to get out of here." << std::endl;}
/**********************************************************************************
 * void Room::actions(int num, Room* choice, Char* player, Maggie* npc, Joe* npc2);
 * Purpose: Prints the possible actions available to the user
 * Entry: None
 * Exit: Prints possible actions to the screen
 * ******************************************************************************/		
int Room::actions(int num, Room* choice, Char* player, Maggie* npc, Joe* npc2){
	int n;
	int m;
	std::string input;

	/* Conversation branch */
	if(num == 1){

		/* People Around */
		if(getName() == "House"){
			std::cout << std::string(50, '\n');
			npc->getDescription();
			m = player->conversation(npc);
			m = npc->conversation(m);
			n = 5;}
		if(getName() == "JoesHouse"){
			std::cout << std::string(50, '\n');
			npc2->getDescription();
			m = player->conversation(npc2);
			m = npc2->conversation(m);
			n = 5;}

		/* No one Around */
		else if(getName() != "House" && getName() != "JoesHouse"){
			std::cout << std::string(50, '\n');
			if(getName() == "Street" || getName() == "Street2")
				std::cout << "Anyone worth talking to is long inside and sleeping this time of night. Like you should be." << std::endl;
			else
				std::cout << "\nIt's a sewer. It's gross. Did you really think there'd be someone to talk to? There's not." << std::endl;
			n = 5;}}


	/* Item useage branch */
	if(num == 2){
		Item* thing = new Item;
		std::cout << std::string(50, '\n');
		thing = getItem(player);
		if(player->getHP() <= 0)
			return 0;
		if(thing != NULL){
			std::cout << std::string(50, '\n');
			interactItem(thing, player);}
		n = 5;}


	/* Required hint/help menu for the grader */
	if(num == 4){
		std::cout << std::string(50, '\n');
		std::cout << "You are required to find the following items to succeed: " << std::endl;
		std::cout << "     1. Metal to make a grappling hook" << std::endl;
		std::cout << "     2. Hair pins to pick a lock" << std::endl;
		std::cout << "     3. Pantyhose to be a makeshift rope" << std::endl;
		std::cout << "     4. Booze to celebrate your awesomeness" << std::endl;
		std::cout << "\nYou must do this before you try 16 rooms, or you will lose." << std::endl;
		std::cout << "You must then reach the final room with the items, and it will take you to end game." << std::endl;
		n = 5;}


	/* Moving branch */
	if(num == 3){
		std::cout << std::string(50, '\n');
		if(getName() == "House" || getName() == "JoesHouse"){
			std::cout << "Your eyes roam over plain walls, decorated with sprinklings of decaying wood. You search for an easy exit without ";
			std::cout << "making too much noise. As it is, you hear the rustling of movement in the near distance.." << std::endl;}
		if(getName() == "Street")
			std::cout << "You jog along the alley, searching for grates, ladders, or any big sign declaring 'Exit Here!'" << std::endl;
		else if(getName() != "House" && getName() != "JoesHouse" && getName() != "Street"){
			std::cout << "\nYou wander along the edges of the walls, wiping away years of caked on filth. Slowly, you search for any stone that ";
			std::cout << "might give way, or any passage that may be hidden." << std::endl;}
		std::cout << "\nDo you try: " << std::endl;
		std::cout << "     1. North " << std::endl;
		std::cout << "     2. South " << std::endl;
		std::cout << "     3. East " << std::endl;
		std::cout << "     4. West " << std::endl;

		std::cout << "Try a Direction: ";
		std::getline(std::cin, input);
		m = atoi(input.c_str());
		n = getDoor(m, choice);
		
		while(n == 5){
			std::cout << "Try a Different Direction: ";
			std::getline(std::cin, input);
			m = atoi(input.c_str());
			n = getDoor(m, choice);}}
	return n;}


	

/******************************************************************
 * Room* Room::move(int direction);
 * Purpose: Determines the linking path
 * Entry: Direction of travel
 * Exit: Returns link in direction of travel of user choice
 * ***************************************************************/		
Room* Room::move(int direction){
	if(direction == 1)
		return this->north;
	if(direction == 2)
		return this->south;
	if(direction == 3)
		return this->east;
	if(direction == 4)
		return this->west;}


/******************************************************************
 * Item* Room::getItem(Char* player)
 * Purpose: Prints out default no items found message
 * Entry: User's character
 * Exit: Returns NULL to indicate no items found
 * ***************************************************************/		
Item* Room::getItem(Char* player){
	std::cout << "\nUnless you like rats and filth there's not a lot to look at, much less use." << std::endl;
	Item* choice = NULL;
	return choice;}


/******************************************************************
 * void Room::interactItem(Item* pick, Char* player);
 * Purpose: Prints menu for actions user can take with an item. 
 * Calls the item's functio for an appropriate message to be
 * displayed.
 * Entry: Character and item of character choice
 * Exit: Prints menu to screen, prints appropriate item specific
 * action to string for each of the user's choices
 * ***************************************************************/		
void Room::interactItem(Item* pick, Char* player){
	int num;
	std::string input;

	std::cout << "You hold up the " << pick->getName() << ". " << std::endl;
	std::cout << "What do you want to do with it? " << std::endl;
	std::cout << "\n1. Take it with you. Duh. " << std::endl;
	std::cout << "\n2. Use it " << std::endl;
	std::cout << "\n3. Throw it back. Why did you even touch it? Ugh.." << std::endl;
	std::cout << "\n4. What is it? Look closer..." << std::endl;
	std::cout << "\nYour pick: ";
	std::getline(std::cin, input);
	num = atoi(input.c_str());

	std::cout << std::string(50, '\n');
	if(num == 1){
		if(pick->getHoldable() == true)
			player->addItem(pick);
		else
			std::cout <<"Why you thought you could fit that in your bag you'll never know. Unfortunately, after a struggle, you put it back."<< std::endl;}
	if(num == 2)
		pick->getAction();
	if(num == 3)
		std::cout << "You chuck the " << pick->getName() << " across the room. Splat!" << std::endl;
	if(num == 4)
		pick->getDesc();}
