#include <iostream>
#include <fstream>
#include <string>

/************************************************
 * void readStory(int num)
 * Purpose: Reads files and prints contents to
 * screen
 * Entry: Number indicating which file needs to
 * be opened and read
 * Exit: File printed to screen
 * ********************************************/
void readStory(int num)
{
	std::ifstream fin;
	std::string input;

	/* Story Beginning */
	if(num == 1){
		fin.open("StoryOne.txt");
		if(fin.fail())
			std::cout << "The file was not found." << std::endl;
		while(std::getline(fin, input)){
			std::cout << input << std::endl;}
		fin.close();}

	/* Character Creation */
	if(num == 2){
		fin.open("StoryTwo.txt");
		if(fin.fail())
			std::cout << "The file was not found." << std::endl;
		while(std::getline(fin, input)){
			std::cout << input << std::endl;}
		fin.close();}

	/* Happy Ending */
	if(num == 3){
		fin.open("StoryEnd.txt");
		if(fin.fail())
			std::cout << "The file was not found." << std::endl;
		while(std::getline(fin, input)){
			std::cout << input << std::endl;}
		fin.close();}
}


