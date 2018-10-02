/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: main.cpp is the program file that runs the train game.
************************************************************************************************/
#include <iostream>
#include "Game.hpp"
#include "validate.hpp"

void displayMenu();
void actOnChoice(int);

int main(){
	//	hold user choice
	int choice;

	//	loop until user decides to exit
	do{
		//  calls menu function which displays 2 options 1) play 2) quit
		displayMenu();
		choice = validate(1,2);
		actOnChoice(choice);
	}while(choice != 2);

    return 0;
}


/***************************************************************************
							displayMenu()
	This is a menu function that will display the menu before the game
	starts. It allows the user to choose between two options.
	1) play
	2) exit
****************************************************************************/
void displayMenu(){
	std::cout << "\n\nWelcome to the train game!" << std::endl;

    std::cout << "\n\n\tMenu\n\n";
    std::cout << "1) Start game\n";
    std::cout << "2) Exit\n";
	std::cout << "Enter your choice: " << std::endl;
}


/***************************************************************************
							actOnChoice(int)
	This function has one int parameter. The user input to the menu is 
	passed as an argument to this function. If the user chooses 1, then
	the game is played. Else the game is exited.
****************************************************************************/
void actOnChoice(int selection){
	switch(selection){
		//	Play game
		case 1:
		{
			Game game;
			game.play();
			break;
		}
		//	Quit
		case 2:
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
	}
}