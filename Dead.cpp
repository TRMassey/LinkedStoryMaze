#include "World.h"
#include "Room.h"
#include "Dead.h"
#include "Char.h"
#include <iostream>
#include <string>

/*************************************************************************************
 * Dead::Dead(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a new dead end room
 * **********************************************************************************/
Dead::Dead(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}



/*************************************************************************************
 * void Dead::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void Dead::setDesc(){
	description = "The room was once large, but now is only a fraction of it's original size due to a large collapse.";}



/*************************************************************************************
 * void Dead:getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void Dead::getDesc(){
	std::cout << "You slip through the small opening you've found, and then sigh with disgust when you see the new area." << std::endl;
	std::cout << description << std::endl;}


/*************************************************************************************
 * Item* Dead::getItem(Char* player)
 * Purpose: Prints items available in room for interaction, as well as reaction if the
 * item is selected. This room has a trap for choice one, which reduced the player's
 * health points by half.
 * Entry: Character interacting with the items
 * Exit: Returns the item the player would like to interact with, unless it is the
 * trapped item, in which case "NULL" is returned.
 * **********************************************************************************/
Item* Dead::getItem(Char* player){
	int num;
	std::string input;

	std::cout << "Your eyes roam the dead end room. All you really see is..: " << std::endl;
	std::cout << "\n1. One tiny rock near the bottom" << std::endl;
	std::cout << "\n2. One big manly rock that's lookin' at you funny" << std::endl;
	std::cout << "\nYour pick: ";
	std::getline(std::cin, input);
	num = atoi(input.c_str());

	if(num == 1){
		Item* pick = NULL;
		std::cout << std::string(50, '\n');
		std::cout << "You pull out the rock, and they all come tumbling. You're quick, but not quite quick enough to stop from " << std::endl;
		std::cout << "getting a few good thwacks from the falling debris." << std::endl;
		player->setHP(5);
		if(player->getHP() <= 0)
			return pick;
		std::cout << "\nYour health is now at " << player->getHP() << " so be careful! No more rock slides. You have a death wish?" << std::endl;
		return pick;}
	if(num == 2){
		Item* pick = new Item("Big Rock", "A rock the size of a pumpkin.", false, false, "You kick it. It didn't hurt it, but you did it.");
		return pick;}}
