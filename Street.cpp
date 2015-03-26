#include "World.h"
#include "Room.h"
#include "Street.h"
#include "House.h"
#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>

/*************************************************************************************
 * Street::Street(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a Street room
 * **********************************************************************************/
Street::Street(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void Street::getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void Street::setDesc(){
	description = "A narrow dimly lit alley opens before you, only slightly less fragrant than the sewers you've escaped.";}


/*************************************************************************************
 * void Street::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void Street::getDesc(){
	std::cout << "You dart out of the house, choosing to risk the streets over the yelling you hear from the home behind you." << std:: endl;
	std::cout << "You skid to a stop, taking a moment to catch your breath (we'll leave that out of the story), and get a look around you. " << std::endl;
	std::cout << description << std::endl;
	std::cout << "Lady Luck appears to feel seriously scorned." << std::endl;}


