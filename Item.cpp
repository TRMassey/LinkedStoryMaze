#include "Item.h"
#include <iostream>
#include <string>

/**************************************************************************
 * Item::Item()
 * Purpose: Constructor
 * Entry: None
 * Exit: New Item created
 * ***********************************************************************/
Item::Item(){
	this->name = "item";
	this->description = "none";
	this->holdable = false;
	this->key = false;
	this->action = "none";}


/**************************************************************************
 * Item::Item(std::string n, std::string d, bool h, bool k)
 * Purpose: Constructor
 * Entry: Item name, item description, if the item is holdable, if the
 * item is a key to exit, and item specific action
 * Exit: New Item created
 * ***********************************************************************/
Item::Item(std::string n, std::string d, bool h, bool k, std::string a){
	this->name = n;
	this->description = d;
	this->holdable = h;
	this->key = k;
	this->action = a;}


/**************************************************************************
 * Item::~Item()
 * Purpose: Deconstructor
 * Entry: None
 * Exit: Deconstruction of item class
 * ***********************************************************************/
Item::~Item(){}


/**************************************************************************
 * void Item::getAction()
 * Purpose: View available actions for an item
 * Entry: None
 * Exit: Prints available actions for a selected item
 * ***********************************************************************/
void Item::getAction(){
	std::cout << std::string(50, '\n');
	std::cout << action << std::endl;}


/**************************************************************************
 * std::string getName()
 * Purpose: Returns the name of the item
 * Entry: None
 * Exit: Returns the name of the item
 * **********************************************************************/
std::string Item::getName(){
	return name;}


/**************************************************************************
 * void getDesc();
 * Purpose: Returns the decription of the item
 * Entry: None
 * Exit: Returns the description of the item
 * **********************************************************************/
void Item::getDesc(){
	std::cout << description << std::endl;}


/**************************************************************************
 * bool getHoldable();
 * Purpose: Returns if the player can carry the item
 * Entry: None
 * Exit: Returns if the player can carry the item
 * **********************************************************************/
bool Item::getHoldable(){
	return holdable;}


