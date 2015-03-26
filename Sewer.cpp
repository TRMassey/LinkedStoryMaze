#include "World.h"
#include "Room.h"
#include "Sewer.h"
#include "Char.h"
#include <iostream>
#include <string>

/*************************************************************************************
 * Sewer::Sewer(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a Sewer room
 * **********************************************************************************/
Sewer::Sewer(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void Sewer::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void Sewer::setDesc(){
	description = "Moss and slime coat long, grated walls. Water and debris stagnate in the middle of the room.";}


/*************************************************************************************
 * void Sewer:getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void Sewer::getDesc(){
	std::cout << "You hop down a small ridge to find yourself in another room." << std:: endl;
	std::cout << description << std::endl;
	std::cout << "Luckily, there are small, crumbing paths near the walls where you can get out of the muck." << std::endl;}


