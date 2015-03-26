#include "World.h"
#include "Room.h"
#include "House.h"
#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>

/*************************************************************************************
 * House::House(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a new Maggie's House room
 * **********************************************************************************/
House::House(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void House::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void House::setDesc(){
	description = "Four shabby walls surround you, permiated with the smell of boiled cabbage, and a thatch roof.";}


/*************************************************************************************
 * void House:getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void House::getDesc(){
	std::cout << "You eye a few rusted handholds, screwed into the walls by some engineering fellow. With a shrug, you decide to test " << std::endl;
	std::cout << "your luck. You grab hold and begin to pull yourself up. When you reach the top, you push aside a wood panel and peek out. " << std::endl;
	std::cout << description << std::endl;
	std::cout << "This looks oddly familiar. Were you here before? Naw... couldn't be..." << std::endl;}


/*************************************************************************************
 * Item* House::getItem(Char* player)
 * Purpose: Prints items available in room for interaction and gets selection.
 * Entry: Character interacting with the items
 * Exit: Returns the item selected
 * **********************************************************************************/
Item* House::getItem(Char* player){
	int num;
	std::string input;

	std::cout << "Your eyes roam the dirty little house. A few items pop out at you: " << std::endl;
	std::cout << "\n1. Hair pins" << std::endl;
	std::cout << "\n2. Pantyhose" << std::endl;
	std::cout << "\n3. Chocolate" << std::endl;
	std::cout << "\nYour pick: ";
	std::getline(std::cin, input);
	num = atoi(input.c_str());

	if(num == 1){
		Item* pick = new Item("Hair pins", "A few small black pins.", true, true, "You stick them in your hair. Stylin'.");
		return pick;}
	if(num == 2){
		Item* pick = new Item("Pantyhose", "An overly stretched set of women's undergarmets.", true, true, "You start putting them on. Wont fit.");
		return pick;}
	if(num == 3){
		Item* pick = new Item("Chocolate", "It's cholate!", true, false, "You pop a piece in your mouth.");
		return pick;}}

