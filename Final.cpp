#include "World.h"
#include "Room.h"
#include "Final.h"
#include "Char.h"
#include "Item.h"
#include <iostream>
#include <string>


/*************************************************************************************
 * Final::Final(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a room before the final room
 * **********************************************************************************/
Final::Final(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void Final::setDesc()
 * Purpose: Sets the custom description
 * Entry: None
 * Exit: Description changed from "none" to custom description
 * **********************************************************************************/
void Final::setDesc(){
	description = "The room is large, more concrete than fetid pools of collecting water. The walls are tinged green with with age.";}


/*************************************************************************************
 * void Final::getDesc()
 * Purpose: Prints the custom description
 * Entry: None
 * Exit: Description of room printed
 * **********************************************************************************/
void Final::getDesc(){
	std::cout << "You pull yourself through a grating connecting to another room in the sewer system. This one, however, looks promising. " << std::endl;
	std::cout << description << std::endl;
	std::cout << "This is the room they described to  you. This is it! So, anxiously, you look at the northern wall for handholds to get to the " << std::endl;
	std::cout << "desk that will end this stupid, stupid quest. There are none. " << std::endl;
	std::cout << "\nDesperately, you look up, so close to victory. How will you get up there?" << std::endl;}


/*************************************************************************************
 * void Final::interactItem(Item* pick, Char* player)
 * Purpose: Prints the custom interact message
 * Entry: Items and Character interacting
 * Exit: Description of interaction
 * **********************************************************************************/
void Final::interactItem(Item* pick, Char* player){
	std::cout << "\nYou pull out the oddly twisted mental piece you fished from the sewer and tie Maggie's old pantyhose to it. When you ";
	std::cout << "retell this story someday, you're going to say you were smart enough to have brought rope." << std::endl;
	std::cout << "\nA few quick twirls and up it goes, snagging the grate with a too-loud clang. Not perfect, but at least you have a clear ";
	std::cout << "way to get up. Speaking of, you grab the rope, and up-up-up you go!" << std::endl;}


