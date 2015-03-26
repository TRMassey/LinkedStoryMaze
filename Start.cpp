#include "World.h"
#include "Room.h"
#include "Start.h"
#include "Sewer.h"
#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>


/*************************************************************************************
 * Start::Start(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a Starting room
 * **********************************************************************************/
Start::Start(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void Start::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void Start::setDesc(){
	description = "You're in a long, narrow tunnel, filled with muck. The light is dim, and you struggle to see. There appear to be grates along the walls.";}


/*************************************************************************************
 * void Start::getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void Start::getDesc(){
	if(getBenTo() == false){
		std::cout << "\n" << description << std::endl;
		setBenTo();}
	else
		std::cout << "Wait. This is familiar. Crap! Crap! This is where you were thro-- err.. bravely jumped in. Crap." << std::endl;}


/*************************************************************************************
 * Item* Start::getItem(Char* player)
 * Purpose: Prints items available in room for interaction and gets selection.
 * Entry: Character interacting with the items
 * Exit: Returns the item selected
 * **********************************************************************************/
Item* Start::getItem(Char* player){
	int num;
	std::string input;

	std::cout << "Your eyes roam the dirty little house. A few items pop out at you: " << std::endl;
	std::cout << "\n1. Shimmering something in the filth" << std::endl;
	std::cout << "\n2. Rat" << std::endl;
	std::cout << "\nYour pick: ";
	std::getline(std::cin, input);
	num = atoi(input.c_str());

	if(num == 1){
		Item* pick = new Item("Metal", "A twisted up, sharp piece of metal.", true, true, "You wave it around. Yep. You're ridiculous.");
		return pick;}
	if(num == 2){
		Item* pick = new Item("Rat", "A squeaky, adorable, disease carrier.", true, false, "You grab the little guy up to pet him. Squeaky!");
		return pick;}}

