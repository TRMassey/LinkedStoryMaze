#include "Char.h"
#include "Maggie.h"
#include <iostream>
#include <string>
#include <vector>

/*************************************************************
 * Maggie() : Char(std::string n, std::string d)
 * Purpose: constructor
 * Entry: Npc's name and description
 * Exit: Creates a new Npc
 * *********************************************************/
Maggie::Maggie() : Char(){
	this->name = "Maggie";
	this->description = "A 5 foot tower of glowering, red haired ex-girlfriend.";
	this->talkTwice = false;}



/************************************************************
 * virtual std::string getName()
 * Purpose: returns Maggie's name
 * Entry: None
 * Exit: Returns a string that is Maggie's name
 * ********************************************************/
std::string Maggie::getName(){
	return name;}


/***********************************************************
 * virtual std::string getDesc()
 * Purpoes: return's Maggie's description
 * Entry: None
 * Exit: Returns a string that is Maggie's description
 * ********************************************************/
void Maggie::getDescription(){
	if(getTalkTwice() == false){
		std::cout << "A short, curvy form rounds the corner. You can work with this. That is, until ";
		std::cout << "you get a good glimpse of who it is. Snap." << std::endl;
		std::cout << "Pride, meet Maggie. You remember Maggie, right?" << std::endl;
		std::cout << description << std::endl;}
	else{
		std::cout << "You look around in a panic, but no one else is in sight. Well, maybe she's going " << std::endl;
		std::cout << "to leave. You close your eyes and count to 10. Then you peek one open..." << std::endl;
		std::cout << "Nope. Still there, glowering." << std::endl;}}


/************************************************************
 * virtual void getSpeech()
 * Purpose: First conversation player can have with NPC
 * Entry: None
 * Exit: Prints the first conversation from the NPC
 * ********************************************************/
int Maggie::conversation(int num){
	if(num == 1 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "\nMaggie's eyes narrow dangerously. You're on thin ice, and you know it. Now would be an amazing time to stop " << std::endl;
		std::cout << "talking. If only that self preservation instinct kicked in before you opened your mouth..." << std::endl;
		std::cout << "\n'Ya thinks yer funny, do ya?' Maggie steps closer, the color in her cheeks slowly darkening to match her hair." << std::endl;
		setTalkTwice();
		return 5;}
	if(num == 2 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "\nMaggie puts her hands on her hips, eyes narrowing slightly. She hasn't reached for anything within throwing distance, " << std::endl;
		std::cout << "so you're doing pretty well, all things considered." << std::endl;
		std::cout << "\n'A 'Hey Darlin' is all 'em worth, huns?' Maggie questions, her foot starting to tap with irritation. This could be going " <<std::endl;
		std::cout << "better, but there's still hope of saving this." << std::endl;
		std::cout << "\n'After you done get and run out last time 'round ya'd think ya'd show up with some drink or flowers or...' Maggies nose " << std::endl;
		std::cout << "scrunches, and she takes a step away. She eyes you warily. 'Or at least aint smelling like..' Maggie makes a choking sound. "<<std::endl;
		std::cout << "'Ugh, gads... get! Get goin' again! Ya smell like ya got stuck in the outhouse in summer.' " << std::endl;
		setTalkTwice();
		return 5;}
	if(num == 3 && getTalkTwice() == false){
		std::cout << std::string(50, '\n');
		std::cout << "'Darlin,' Maggie purrs, taking a step closer. 'Ya ain' even begun ta see hell.' " << std::endl;
		std::cout << "\nSmart enough to know when a man's hearing his final words, you grab scramble backwards and away from the unstable and " << std::endl;
		std::cout << "scorned woman. In retrospect, this may even be a better memory for her. After all, this time you're leaving out a door and " << std::endl;
		std::cout << "not the window." << std::endl;
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
void Maggie::talkedTwice(){
	std::cout << std::string(50, '\n');
	std::cout << "A book (filled with pretty pictures) goes flying by your head. She has a good arm. " << std::endl;
	std::cout << "'Just... get... OUT!' Maggie shouts" << std::endl;}


/*******************************************************************
 * void Maggie::setTalkTwice()
 * Purpose: Signals if the player has already talke dto Maggie
 * Entry: none
 * Exit: Player now recorded as having talked to Maggie
 * ****************************************************************/
void Maggie::setTalkTwice(){
	talkTwice = true;}


/***********************************************************************
 * bool Maggie::getTalkTwice()
 * Purpose: Returns if the character has spoken with Maggie
 * Entry: None
 * Exit: Return true if character has spoken with Maggie
 * **********************************************************************/
bool Maggie::getTalkTwice(){
	return talkTwice;}


