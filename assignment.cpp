/***************************************************************************
 * Program Filename: aassignment.cpp
 * Author: Tara Massey
 * Date: 03/17/2015
 *
 * Desription: Program creates a choose your own adventure text game. The
 * program consists of linked classes. Every room will have four pointers to
 * other rooms. The base class for the rooms is abstract. The character will
 * have to navigate the maze while picking up items to succeed in the last
 * room. The character will be allowed to interact with distinct and unique
 * rooms.
 *
 * Input: The user selects their name and title. The user can select to
 * look for someone to talk to, look aroud for items, leave, or read the
 * help menu in each room. When selecting someone to talk to, if applicable,
 * the user can select various conversation choices. If the user selects to
 * look for an item, if applicable, the user can keep the item, use the item,
 * throw the item, or look at the item. The program reads texts from three
 * seperate files to create the story.
 *
 * Output: The program prints the stories to the screen, and the various menus.
 * The program prints appropriate responses to each menu selection, with
 * room dependent options. The program creates new drived classes and assigns
 * them to a Room pointer. Appropriate notification regarding health and time
 * are printed to the screen.
 *
****************************************************************************/

#include "World.h"
#include "Room.h"
#include "Start.h"
#include "Sewer.h"
#include "Secret.h"
#include "Dead.h"
#include "Street.h"
#include "House.h"
#include "JHouse.h"
#include "Final.h"
#include "End.h"
#include "Maggie.h"
#include "Joe.h"
#include "Char.h"
#include "Item.h"

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>


void readStory(int num);

int main()
{
	std::string input;
	std::string inputTwo;
	int pick = 5;

	/* Create a world state of possible rooms */
	World* state = new World;
	state->createWorld();

	
	/* Begin the introduction to the story */
	std::cout << std::string(100, '\n');
	readStory(1);


	/* Create your hero */
	std::cout << "\nYou pull back your shoulders, and in your best attempt to hide your terror you give your name:  ";
	std::getline(std::cin, input);
	std::cout << "\nWhile your at it, you may as well make up an amazing, unforgetable, badass nickname: ";
	std::getline(std::cin, inputTwo);
	std::cout << std::string(100, '\n');
	Char* player = new Char(input, inputTwo);


	/* Learn about your predicament and the goal */
	std::cout << " 'Right... Mr. " << player->getName() << " the " << player->getDesc() << "'" << std::endl;
	std::cout << "\n";
	std::cout << std::string(100, '\n');	
	readStory(2);
	std::cout << "\nPRESS ENTER TO BEGIN YOUR JOURNEY" << std::endl;
	std::getline(std::cin, input);
	std::cout << std::string(100, '\n');


	/* Pull up starting room and story characters */
	Room* currentRoom = state->startPnt();
	Maggie* npc = new Maggie;
	Joe* npc2 = new Joe;

	/* While the player still has health & time, implement action loop for all rooms but Final/End, Different actions for Final/End, and link to next*/
	while(player->getLost() == false){

		if(currentRoom->getName() != "Final" && currentRoom->getName() != "End"){
			state->addPath(currentRoom);
			player->setLocation(currentRoom->getName());
			std::cout << std::string(100, '\n');
			currentRoom->setDesc();
			currentRoom->getDesc();					
			state->timer(player);		
				while(pick == 5){
					std::cout << "\nPossible Actions: ";
					currentRoom->printActions();				
					std::cout << "\nWhat would you like to do?" << std::endl;	
					std::getline(std::cin, input);
					std::cout << std::string(100, '\n');
					pick = atoi(input.c_str());
					pick = currentRoom->actions(pick, currentRoom, player, npc, npc2);}	
			Room* temp = currentRoom->move(pick);						// Go to next link
			currentRoom = temp;
			pick = 5;}	
		
		/* Special/Limited Actions for Room Prior to Winning */
		if(currentRoom->getName() == "Final"){							
			player->setKeys();
			player->setLocation(currentRoom->getName());
			state->timer(player);
			state->addPath(currentRoom);

			/* Player has the keys to access the final room */
			if(player->getKeys() == true){
				std::cout << "You take a peek in your bag to see if you can figure out a way up to the grate." << std::endl;
				player->viewBag();
				std::cout << "\nYou can absolutely work wit that. You did it!" << std::endl;
				Item* all = new Item;
				currentRoom->interactItem(all, player);
				pick = 1;
				Room* temp = currentRoom->move(pick);					// Go to next link
				currentRoom = temp;}
				
			/* Player does not have the keys to get to the final room */
			else{
				currentRoom->setDesc();
				currentRoom->getDesc();
				std::cout << "You look desperately through your pack. Unfortunately, you don't have what you need to ";
				std::cout << "be able to access the grate so very far above your head." << std::endl;
				player->viewBag();
				currentRoom->printActions();
				std::cout << "\nWhat would you like to do?" << std::endl;
				std::getline(std::cin, input);
				std::cout << std::string(100, '\n');
				pick = atoi(input.c_str());
				pick = currentRoom->actions(pick, currentRoom, player, npc, npc2);	
				Room* temp = currentRoom->move(pick);					// Go to next link
				currentRoom = temp;
				pick = 5;}}


		/* Final Room, Access the room, get the description, and Read End file to exit */
		if(currentRoom->getName() == "End"){
			currentRoom->setDesc();
			currentRoom->getDesc();
			std::cout << "You take a peek in your pack, thankful you have the hair pins to pick the lock, and the booze to celebrate." << std::endl;
			readStory(3);

			/* View stats and clean up pointers */
			std::cout << "\nGame Choices: " << std::endl;
			state->viewWorld();
			state->viewPath();
			return 0;}}

		


	/* Losing conditions */
	if(player->getHP() <= 0){
		std::cout << "\nWell... you died. You were warned in the beginning, remember?" << std::endl;}

	else{
		std::cout << "\nYou drop to your knees, bowing your head in shame and frustration. You can see the sun beginning to rise. " << std::endl;
		std::cout << "You tried, but you weren't able to pull off the heist in time. " << std::endl;}



	/* View World State, including winning choices and your choices */
	std::cout << "\nGame Choices: " << std::endl;
	state->viewWorld();
	state->viewPath();

return 0;
}

