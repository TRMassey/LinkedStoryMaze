#include "Char.h"
#include "Joe.h"
#include <iostream>
#include <string>
#include <vector>

/*************************************************************
 * Joe() : Char(std::string n, std::string d)
 * Purpose: constructor
 * Entry: Npc's name and description
 * Exit: Creates a new Npc
 * *********************************************************/
Joe::Joe() : Char(){
	this->name = "Joe";
	this->description = "A lanky old man with teeth yellowed from years of tobacco.";
	this->talkTwice = false;}



/************************************************************
 * virtual std::string getName()
 * Purpose: returns Joes name
 * Entry: None
 * Exit: Returns a string that is Maggie's name
 * ********************************************************/
std::string Joe::getName(){
	return name;}


/***********************************************************
 * virtual std::string getDesc()
 * Purpoes: return's Joes description
 * Entry: None
 * Exit: Returns a string that is Maggie's description
 * ********************************************************/
void Joe::getDescription(){
	if(getTalkTwice() == false){
		std::cout << "A heavily bearded face lifts itself from its' resting place on a nearby tabletop, smiling." << std::endl;
		std::cout << description << " A smile that's half drunk on it's best day. Drooping eyes that are just a bit too keen to be drunk." << std::endl;
		std::cout << "You walked into Crazy Joe's house. You've made better decisions in life." << std::endl;}
	else{
		std::cout << "Just count to 10 and wait for him to lay his head down. He may go back to sleep, because God knows " << std::endl;
		std::cout << "there's no one else in this house. He has no friends. He has no relatives. He may have eaten his pets, or " << std::endl;
		std::cout << "blown them up. Yep, that's right. *Crazy* Joe." << std::endl;}}


/************************************************************
 * virtual void getSpeech()
 * Purpose: First conversation player can have with NPC
 * Entry: None
 * Exit: Prints the first conversation from the NPC
 * ********************************************************/
int Joe::conversation(int num){
	if(num == 1 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "\nJoe squints his eyes at you, attempting to get a better look. He's not trying hard enough to actually have to " << std::endl;
		std::cout << "move, mind you, but you can tell what's left of his brain is trying it's hardest to put two and two together." << std::endl;
		std::cout << "\n'That's me... buddy,' Well, obviously Joe lost that fight. Whatever. It's for the best." << std::endl;
		setTalkTwice();
		return 5;}
	if(num == 2 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "\nJoe grunts and drops his face back down onto the table." << std::endl;
		std::cout << "\n'I aint never touching that slop again if yer the best my brain can come up with after last nigh'...'" << std::endl;
		std::cout << "\nYou look a bit taken aback. How dare that drunk judge you? But... I suppose that's neither here nor there..." <<std::endl;
		setTalkTwice();
		return 5;}
	if(num == 3 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "Joe's head snaps back and then lands back on the table, right it its' original pillow of drool." << std::endl;
		std::cout << "\nCongrats. Now your  hand hurts and he's no worse off than when you found him. You're a genius. " << std::endl;
		setTalkTwice();
		return 5;}
	else
		talkedTwice();}



/*************************************************************
 * void talkTwice()
 * Purpose: Repeats an ending conversation if the player keeps
 * interacting with the NPC
 * Entry: None
 * Exit: Prints an ending conversation to the screen
 * *********************************************************/
void Joe::talkedTwice(){
	std::cout << std::string(50, '\n');
	std::cout << "Crazy Joe grunts, his head back down on the table in a pile of hours of drool. He's out cold." << std::endl;}


/*******************************************************************
 * void Joe::setTalkTwice()
 * Purpose: Signals if the player has already talked to Joe
 * Entry: none
 * Exit: Player now recorded as having talked to Joe
 * ****************************************************************/
void Joe::setTalkTwice(){
	talkTwice = true;}


/***********************************************************************
 * bool Joe::getTalkTwice()
 * Purpose: Returns if the character has spoken with Joe
 * Entry: None
 * Exit: Return true if character has spoken with Joe
 * **********************************************************************/
bool Joe::getTalkTwice(){
	return talkTwice;}


