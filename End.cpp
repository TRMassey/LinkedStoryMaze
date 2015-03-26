#include "World.h"
#include "Room.h"
#include "End.h"
//#include "Sewer.h"
#include "Char.h"
//#include "Maggie.h"
#include <iostream>
#include <string>


/*************************************************************************************
 * End::End(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a end dead end room
 * **********************************************************************************/
End::End(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void End::setDesc()
 * Purpose: Sets the custom description
 * Entry: None
 * Exit: Description changed from "none" to custom description
 * **********************************************************************************/
void End::setDesc(){
	description = "\nYou see a beautifully furnished room with a desk front and center. Bingo, that's your target.";}


/*************************************************************************************
 * void End::getDesc()
 * Purpose: Prints the custom description
 * Entry: None
 * Exit: Description of room printed
 * **********************************************************************************/
void End::getDesc(){
	std::cout << std::string(100, '\n');
	std::cout << "You pull yourself up with a grunt, scooting a grating off to the side. It's the only clean grate you've seen all day." << std::endl;
	std::cout << description << std::endl;}



