/*******************************************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Game.cpp is the Game class implementation file.
********************************************************************************************************************/

#include "Game.hpp"
#include "Space.hpp"
#include "Flick.hpp"
#include "Fire.hpp"
#include "Engine.hpp"
#include "map.hpp"
#include "validate.hpp"

#include <algorithm>
#include <iostream>

/*********************************************************************************************************************
										Game::Game()
	This is the Game constructor. There are 6 space objects that are initialized. The constructor also links
	all the trains by calling the setLeftRight method. It also sets the location of the player to the caboose
	car. 
*********************************************************************************************************************/
Game::Game(){
	//	create spaces train cars
	caboose = new Flick("Caboose car", "flick on the lights", "an emergency brake key");
	bar = new Fire("Bar car", "activate emergency sprinklers", "a bottle of Hennessy");
	shopping = new Fire("Shopping car", "use the fire extinguisher", "an OSU T-Shirt");
	baggage = new Flick("Baggage car", "turn on the lights", "a CS-162 syllabus");
	dining = new Fire("Dining car", "use the fire hose", "a burrito");
	engine = new Engine("Engine car", "activate the emergency brake", "a hero badge");

	//	Link all trains
	caboose->setLeftRight(nullptr, bar);
	bar->setLeftRight(caboose, shopping);
	shopping->setLeftRight(bar, baggage);
	baggage->setLeftRight(shopping, dining);
	dining->setLeftRight(baggage, engine);
	engine->setLeftRight(dining, nullptr);

	//	set starting location to caboose
	location = caboose;
	//	initialize steps to 0
	steps = 0;
	//	player is not hero yet because train has not been saved yet
	hero = false;
} 



/*****************************************************************************************************************
										void Game::displayGoal()
	This function displays the goal of the game. It also displays tips on items.
******************************************************************************************************************/
void Game::displayGoal(){
	std::cout << "\n\n\t\t\t\tWelcome\n" << std::endl;
	std::cout << "You are on a train and you feel a violent earthquake shake the ground!\n";
	std::cout << "You see that the tracks up ahead are damaged.\n" << std::endl;

	std::cout << "Goal:\nStop the train from derailing! Travel through the train from the caboose to the engine.\n";
	std::cout << "Along the way you will find items. One important item is ";
	std::cout << "\"an emergency brake key\".\nYou will need this item in order to stop the train from derailing!" << std::endl;
	std::cout << "In order to win the game you will need to earn \"a hero badge\"!" << std::endl;
	std::cout << "This item is awarded once you successfully stop the train!\n" << std::endl;

	std::cout << "\nTip:\nItems can only be picked up once. If you drop an item, it's gone forever!" << std::endl;
	std::cout << "You can only carry up to 3 items at a time.\n" << std::endl;
}



/*******************************************************************************************************************
 											void Game::displaySteps()
						This function displays steps taken and how many steps are remaining.
 *******************************************************************************************************************/
void Game::displaySteps(){
	//	display steps taken and steps remaining
	std::cout << "************ Step Information ***************" << std::endl;
	std::cout << "\nSteps taken: " << steps << std::endl;
	std::cout << "Steps remaining: " << 20 - steps << std::endl;

	std::cout << std::endl;
}


/*********************************************************************************************************************
									void Game::inGameMenu()
This function displays the in game menu. The in game menu gives the user 3 options
**********************************************************************************************************************/
void Game::inGameMenu(){
	//	3 options
	int actionChoice;
	bool moved = false;
	do{
		//	display map
		displayMap(location->getCarName());

		std::cout << "\nAction Menu\n";
		std::cout << "1) Left\n";
		std::cout << "2) Right\n";
		std::cout << "3) Check backpack\n";

		std::cout << "Enter your choice: " << std::endl;

		actionChoice = validate(1,3);

		switch(actionChoice){
			//	Go left
			case 1:
			{
				if(location->getLeft() != nullptr){
					location = location->getLeft();
					moved = true;
				}
				else{
					std::cout << "\nThere is no train car to the left!\n" << std::endl;
				}
				break;
			}

			//	Go right
			case 2:
			{
				if(location->getRight() != nullptr){
					location = location->getRight();
					moved = true;
				}
				else{
					std::cout << "\nThere is no train car to the right!\n";
				}
				break;
			}

			//	See backpack
			case 3:
			{
				//	print contents of backpack
				this->printContainer();
				break;
			}
		}
	}while(!moved);

	//	increment steps after successfully moving
	steps++;
}



/*************************************************************************************************************
									void Game::printContainer()
			This function prints out the contents of the container. If the container is empty,
			it prints out "you do not have any items in your backpack".
***************************************************************************************************************/
void Game::printContainer(){

	//	print backpack content
	std::cout << "Backpack contents: " << std::endl;
	if(container.empty()){
		std::cout << "You do not have any items in your backpack\n" << std::endl;
	}
	else{
		for(unsigned int i = 0; i < container.size(); i++){
			std::cout << "item " << i + 1 << " - " << container[i] << std::endl;
		}
	}

	//empty line
	std::cout << std::endl;
}



/*************************************************************************************************************
									bool Game::checkHero()
	This function checks to see if you have the "a hero badge" in your container. If you do then the function
	returns true. If you do not the function returns false.

	The function uses the std::find function and has one parameter which is a reference to the string vector
	that represents the container.
***************************************************************************************************************/
bool Game::checkHero(){
		//	iterator used to store the position of searched element
	std::vector<std::string>::iterator it;

	std::string search = "a hero badge";

	//	std::find function call
	it = std::find(container.begin(), container.end(), search);

	if(it != container.end()){
		return true;
	}
	else{
		return false;
	}
}



/*****************************************************************************************************************
												void Game::play()
	This function combines the game functions in order to handle the flow of the game.

	The function increments the steps after the player switches spaces. It checks to see if the hero badge
	has been obtained. If the badge has been obtained it breaks out of the loop and outputs a message 
	based on whether the player has the badge or not.
******************************************************************************************************************/
void Game::play(){
	//	Display goal
	this->displayGoal();

	while(steps <= 20 && !hero){
		//	display steps taken and steps remaining
		this->displaySteps();
		//	display map
		displayMap(location->getCarName());
		std::cout << "**********************************************" << std::endl;

		//	special action based on car
		location->action(container);

		//	check hero status
		this->hero = this->checkHero();

		//	break out of loop if your out of steps
		if(steps == 20){
			break;
		}

		//	if you have the hero badge you won the game 
		if(hero){
			break;
		}
		//	display action menu
		this->inGameMenu();
	}

	//	if you lost the game
	if(!hero){
		std::cout << "\nYou ran out of time and the train derailed! You lost!\n" << std::endl;
		std::cout << "***********************************************" << std::endl;
	}
	//	if you won the game
	else{
		std::cout << "\nYou are a hero and saved the train from derailing! Game Won!\n" << std::endl;
		std::cout << "***********************************************" << std::endl;
	}
}



/********************************************************************************************************************
													Game::~Game()
	This is the destructor. It frees memory to ensure no memory leaks are present in the program.
*********************************************************************************************************************/
Game::~Game(){

	//	If you lose the game then set player to engine car to avoid memory leaks
	if(this->hero == false){
		while(location->getRight() != nullptr){
			location = location->getRight();
		}
	}

	//	delete cars from the engine to the caboose
	while(location->getLeft() != nullptr){
		Space* temp = location;
		location = location->getLeft();
		delete temp;
	}
	delete location;
}