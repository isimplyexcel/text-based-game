/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Engine.cpp is the Engine class implementation file.
************************************************************************************************/

#include "Engine.hpp"	//	includes Space.hpp
#include "validate.hpp"
#include <iostream>
#include <algorithm>

/***********************************************************************************************
		Engine::Engine(std::string m_name, std::string m_action, std::string m_item)
This is the constructor. It has 3 string parameters that will set the name, action, and item
names by calling the space constructor.
************************************************************************************************/
Engine::Engine(std::string name, std::string action, std::string item):Space(name, action, item)
{

}



/************************************************************************************************
								void Engine::action()
	This function will describe the current car and what action the player can take.
	This function overrides the base class pure virtual function. In this function the player 
	will turn on the light since the car is dark.
*************************************************************************************************/
void Engine::action(std::vector<std::string>& container){
	//	welcome user to the car
	std::cout << "Welcome to the " << this->getCarName() << "!" << std::endl;

	if(!actionTaken){
		//	Apply the emergency brakes
		std::cout << "The train will derail soon! You must " << this->getActionName() << " in order"
				  << " to stop the train." << std::endl;
	  	std::cout << "1) " << this->getActionName() << "." << std::endl;
	  	std::cout << "Enter your choice: " << std::endl;

	    int stopTrain = validate(1,1);

	    if(this->checkKey(container, "an emergency brake key")){
	    	std::cout << "You used the emergency brake key and stopped the train from derailing!" << std::endl;
	    	actionTaken = true;

	    	//	receive award and win game
	    	this->findItem(container);
	    }
	    else{
	    	std::cout << "You need the emergency brake key in order to stop the train!" << std::endl;
	    }
	}
}



/******************************************************************************************************
			void Engine::findItem(std::vector<std::string>& container)
	This is the function tells the user that an item has been found and gives them 2 choices to
	pickup the item:

	1) yes
	2) no

	If the user chooses to add an item, it will only do so if the size of the vector is less than 6.
*******************************************************************************************************/
 void Engine::findItem(std::vector<std::string>& container){

    //	You find an item
    std::cout << "You have been awarded " << this->getItemName() << "!" << std::endl;
    std::cout << "Would you like to add " << this->getItemName() <<  " to your backpack?\n";
    std::cout << "1) Yes.\n";

    std::cout << "Enter your choice: " << std::endl;
    int choice = validate(1,1);


	if(container.size() == 3){
        //	print backpack content
        std::cout << "\nBackpack contents: " << std::endl;

        for(unsigned int i = 0; i < container.size(); i++) {
            std::cout << "item " << i + 1 << " - " << container[i] << std::endl;
        }

		std::cout << "\nYou already have 3 items. You cannot carry anymore items." << std::endl;

		std::cout << "Would you like to drop the last item?" << std::endl;
		std::cout << "1) Yes.\n";

		std::cout << "Enter your choice: " << std::endl;
		int dropItem = validate(1,1);

		//	container should now have two items
		container.pop_back();

		container.push_back(this->getItemName());
		std::cout << "\nYou added " << this->getItemName() << " to your backpack!" << std::endl;

	}
	else{
		//	add the item to the backpack
		container.push_back(this->getItemName());
		std::cout << "You added " << this->getItemName() << " to your backpack!" << std::endl;
	}	
}



/*************************************************************************************************************
					bool Engine::checkKey()
	This function checks the backpack to see if you have the "emergency brake key". If the 
	backpack contains the key, then it returns true. Else it returns false.

	referenced geeks for geeks https://www.geeksforgeeks.org/stdfind-in-c/
***************************************************************************************************************/
bool Engine::checkKey(std::vector<std::string>& container, std::string search){
	//	iterator used to store the position of searched element
	std::vector<std::string>::iterator it;

	//	print backpack content
	std::cout << "Backpack contents:\n";
	for(unsigned int i = 0; i < container.size(); i++){
		std::cout << "item " << i + 1 << " - " << container[i] << std::endl;
	}

    std::cout << std::endl;

	//	std::find function call
	it = std::find(container.begin(), container.end(), search);

	if(it != container.end()){
		return true;
	}
	else{
		return false;
	}
}
