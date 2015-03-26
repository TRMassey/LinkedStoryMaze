#include "World.h"
#include "Room.h"
#include "Start.h"
#include "Secret.h"
#include "Sewer.h"
#include "Dead.h"
#include "House.h"
#include "JHouse.h"
#include "Street.h"
#include "Final.h"
#include "End.h"
#include "Char.h"
#include "Maggie.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

/*************************************************************************************
 * World::World()
 * Purpose: Constructor
 * Entry: None
 * Exit: Makes a new World State
 * **********************************************************************************/
World::World(){
	start = new Start("start", NULL, NULL, sewer, NULL);
	sewer = new Sewer("Sewer", house, secret, dead, start);
	secret = new Secret("Secret", start, NULL, NULL, NULL);
	dead = new Dead("Dead", NULL, NULL, NULL, sewer);
	house = new House("House", NULL, sewer, street, NULL);
	street = new Street("Street", NULL, NULL, jHouse, house);
	jHouse = new JHouse("JoesHouse", NULL, street2, NULL, street); 
	street2 = new Street("Street2", jHouse, sewer2, NULL, NULL);
	sewer2 = new Sewer("Sewer2", street2, NULL, final, NULL);
	final = new Final("Final", end, NULL, NULL, sewer2);
	end = new End("End", NULL, final, NULL, NULL);
	std::vector<Room*> rooms;
	std::vector<Room*> roomsTwo;
	time = 0;}

/*************************************************************************************
 * World::~World()
 * Purpose: Deconstructor
 * Entry: None
 * Exit: Deletes all pointers, deconstruction of World class
 * **********************************************************************************/
World::~World(){
	delete start;
	delete sewer;
	delete dead;
	delete street;
	delete jHouse;
	delete house;
	delete street2;
	delete sewer2;
	delete final;
	delete end;}



/*************************************************************************************
 * void World::createWorld()
 * Purpose: Creates a new map,and  a new correct route vector
 * Entry: None
 * Exit: Map and correct path vector created
 * **********************************************************************************/
void World::createWorld(){
	start->east = sewer;		// Start then east to Sewer
	sewer->south = secret;		// Sewer then south to secret
	secret->north = start;		// Secret then north to start	
	sewer->east = dead;		// Sewer then east to dead end
	sewer->north = house;		// Sewer then north to house
	house->east = street;		// House then east to street
	street->east = jHouse;		// Street then west to Joes House
	jHouse->south = street2;	// Joes House then south to a new street
	street2->south = sewer2; 	// Street to a new sewer
	sewer2->east = final;		// Sewer then east to final
	final->north = end;		// Final room to game end

	rooms.push_back(start);		// correct path vector
	rooms.push_back(sewer);
	rooms.push_back(house);
	rooms.push_back(street);
	rooms.push_back(jHouse);
	rooms.push_back(street2);
	rooms.push_back(final);
	rooms.push_back(end);}




/*************************************************************************************
 * void World::viewWorld()
 * Purpose: Prints correct path vector
 * Entry: None
 * Exit: vector printed
 * **********************************************************************************/
void World::viewWorld(){
	std::cout << "\nQuickest path to freedom was: " << std::endl;
	for(int i = 0; i < rooms.size(); i++)
		std::cout << rooms[i]->getName() << ", ";
	std::cout << "\nWhile collecting the metal shard, the hair pin, the pantyhose, and a bottle of booze." << std::endl;}



/*************************************************************************************
 * void World::addPath(Room* current)
 * Purpose: adds the current room the player is in to their traveled path vector
 * Entry: None
 * Exit: vector larger by current room
 * **********************************************************************************/
void World::addPath(Room* current){
	roomsTwo.push_back(current);}



/*************************************************************************************
 * void World::viewPath()
 * Purpose: Prints player's path vector
 * Entry: None
 * Exit: vector printed
 * **********************************************************************************/
void World::viewPath(){
	std::cout << "\nYour path choices were: " << std::endl;
	for(int i = 0; i < roomsTwo.size(); i++)
		std::cout << roomsTwo[i]->getName() << ", ";
	std::cout << "\n" << std::endl;}



/*************************************************************************************
 * Room* World::startPnt()
 * Purpose: Returns the starting point of the created world state/map
 * Entry: None
 * Exit: Starting room returned from world state
 * **********************************************************************************/
Room* World::startPnt(){
	return start;}


/*************************************************************************************
 * void World::time(Char* player)
 * Purpose: Notifies the player if their time is running short
 * Entry: Player
 * Exit: Returns a message, or sets the player's status to lost.
 * **********************************************************************************/
void World::timer(Char* player){

	time = time + 1;
	
	if(time == 6){
		std::cout << "\n*******************************************************************************************************" << std::endl;
		std::cout << "You look anxiously at the light starting to trickle in through the grates. You're running out of time!" << std::endl;
		std::cout << "\n*******************************************************************************************************" << std::endl;}

	if(time == 10){
		std::cout << "\n*******************************************************************************************************" << std::endl;
		std::cout << "\nYou're cutting it close now. You need to get to items to get to the assigned room, and something to pick a lock." << std::endl;
		std::cout << "\n*******************************************************************************************************" << std::endl;}

	if(time == 16){
		player->setLost();}}

