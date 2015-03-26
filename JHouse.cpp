#include "World.h"
#include "Room.h"
#include "House.h"
#include "JHouse.h"
#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>


/*************************************************************************************
 * JHouse::JHouse(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a Joe's House room
 * **********************************************************************************/
JHouse::JHouse(std::string t, Room* n, Room* s, Room* e, Room* w) : House(t, n, s, e, w){}


/*************************************************************************************
 * void JHouse::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void JHouse::setDesc(){
	description = "Bottles litter the floor the hovel, and a shabby blanket with liquor stains is draped across a chair by the fire.";}


/*************************************************************************************
 * void JHouse:getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void JHouse::getDesc(){
	std::cout << "You spot a door slighly adjar at the east of the alley. Jogging over, you tentatively give the door a push open and peek in." << std::endl;
	std::cout << description << std::endl;
	std::cout << "Well, not perfect. But on the plus side, no screeching red heads lurk inside... or so you hope." << std::endl;}


/*************************************************************************************
 * Item* JHouse::getItem(Char* player)
 * Purpose: Prints items available in room for interaction and gets selection.
 * Entry: Character interacting with the items
 * Exit: Returns the item selected
 * **********************************************************************************/
Item* JHouse::getItem(Char* player){
	int num;
	std::string input;

	std::cout << "Your eyes roam the disgusting hovel. Behind the filth, a few items pop out at you: " << std::endl;
	std::cout << "\n1. Booze (kinda everywhere)" << std::endl;
	std::cout << "\n2. Old... meat?" << std::endl;
	std::cout << "\n3. Knife" << std::endl;
	std::cout << "\n4. Crazy Joe's booze..." << std::endl;
	std::cout << "\nYour pick: ";
	std::getline(std::cin, input);
	num = atoi(input.c_str());

	if(num == 1){
		Item* pick = new Item("Booze", "A homemade bottle of brew.", true, true, "You take a swig.");
		return pick;}
	if(num == 2){
		Item* pick = new Item("Meat", "A somewhat hard blob...", true, false, "You sniff it. It has fur. You're not eating that.");
		return pick;}
	if(num == 3){
		Item* pick = new Item("Knife", "It's all sharp and pointy. Very scary.", true, false, "You give the air a good jab. Booyah!");
		return pick;}
	if(num == 4){
		Item* pick = NULL;
		std::cout << std::string(50, '\n');
		std::cout << "Crazy Joe suddenly bolts up, slamming his rather sturdy ale cup down on the top of your head. To be fair, you did " << std::endl;
		std::cout << "try and steal..." << std::endl;
		player->setHP(2);
		if(player->getHP() <=0)
			return pick;
		std::cout << "\nYour Health is now at " << player->getHP() << ". So... good luck with that." << std::endl;
		return pick;}}

