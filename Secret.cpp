#include "World.h"
#include "Room.h"
#include "Start.h"
#include "Sewer.h"
#include "Secret.h"
#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>

/*************************************************************************************
 * Secret::Secret(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w)
 * Purpose: Constructor
 * Entry: Name and four Room pointers
 * Exit: Makes a secret room
 * **********************************************************************************/
Secret::Secret(std::string t, Room* n, Room* s, Room* e, Room* w) : Room(t, n, s, e, w){}


/*************************************************************************************
 * void Secret::setDesc()
 * Purpose: Creates the custom room description
 * Entry: None
 * Exit: Description is changed from "none" to new room description
 * **********************************************************************************/
void Secret::setDesc(){
	description = "The channel was obviously dug out by people, with hard packed dirt forming walls all around you.";}


/*************************************************************************************
 * void Secret:getDesc()
 * Purpose: Prints the custom room description
 * Entry: None
 * Exit: Decription is printed to screen
 * **********************************************************************************/
void Secret::getDesc(){
	std::cout << "You grunt with satisfaction when you stumble across what appears to be a hidden tunnel behind some moss." << std::endl;
	std::cout << "Is this all the theives guild has for you? Easy. You hop in and start your crawl toward victory. " << std::endl;
	std::cout << description << std::endl;
	std::cout << "You wiggle and squirm and do a rather undignified crawl the only way the tunnel allows." << std::endl;}


/******************************************************************
 * void Secret::actions(int num, Room* choice);
 * Purpose: Prints the possible actions available to the user
 * Entry: None
 * Exit: Prints possible actions to the screen
 * ***************************************************************/		
int Secret::actions(int num, Room* choice){
	int n;
	if(num == 1){
		std::cout << std::string(50, '\n');
		std::cout << "\nYou're in a glorified hole in the wall... looking for people? Rats, maybe. People, no." << std::endl;
		n = 5;}
	if(num == 2){
		std::cout << std::string(50, '\n');
		std::cout << "\nAll you see is dirt. No one's left anything in this tunnel." << std::endl;
		n = 5;}
	if(num == 3){
		std::cout << std::string(50, '\n');
		std::cout << "\nYou begin to see a bit dim (very dim) of light in front of you. You're nearing the end!" << std::endl;
		std::cout << "\nAll you can try is the way you're scooting: " << std::endl;
		std::cout << "     1. North " << std::endl;

		std::cout << "Try a Direction: ";
		std::cin >> num;
		n = num;}
	return n;}

