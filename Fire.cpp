/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Fire.cpp is the Fire class implementation file.
************************************************************************************************/

#include "Fire.hpp"	//	includes Space.hpp
#include "validate.hpp"
#include <iostream>

/***********************************************************************************************
		Fire::Fire(std::string m_name, std::string m_action, std::string m_item)
This is the constructor. It has 3 string parameters that will set the name, action, and item
names by calling the space constructor.
************************************************************************************************/
Fire::Fire(std::string name, std::string action, std::string item):Space(name, action, item)
{

}



/************************************************************************************************
					void Fire::action()
	This function will describe the current car and what action the player can take.
	This function overrides the base class pure virtual function. 

	This function will have the user put out a fire in the space.
*************************************************************************************************/
void Fire::action(std::vector<std::string>& container){
	//	welcome user to the car
	std::cout << "Welcome to the " << this->getCarName() << "!" << std::endl;

	if(!actionTaken){
		std::cout << "The " << this->getCarName() << " is on fire!" << std::endl;
		std::cout << "You must " << this->getActionName() << " in order"
				  << " to continue." << std::endl;
	  	std::cout << "1) " << this->getActionName() << "." << std::endl;
	  	std::cout << "Enter your choice: " << std::endl;

	    int flickLights = validate(1,1);
	    std::cout << "\nYou " << this->getActionName() << " and extinguished the fire!\n" 
	    		  << "You may now continue to traverse the train!" << std::endl;
	    //	Since the fire is now extinguished, you won't be asked to activate
	    //	sprinklers for this car again
	    actionTaken = true; 
	}
	else{
		std::cout << "You've already taken action in this car, hurry up and make your way to "
		          << "the engine car!" << std::endl;
	}

	if(!itemTaken){
		this->findItem(container);
	}
}



/******************************************************************************************************
			void Fire::findItem(std::vector<std::string>& container)
	This is the function tells the user that an item has been found and gives them 2 choices to
	pickup the item:

	1) yes
	2) no

	If the user chooses to add an item, it will only do so if the size of the vector is less than 6.
*******************************************************************************************************/
 void Fire::findItem(std::vector<std::string>& container){
	     //	You find an item
    std::cout << "You found " << this->getItemName() << "!" << std::endl;
    std::cout << "Would you like to add " << this->getItemName() <<  " to your backpack?\n";
    std::cout << "1) Yes.\n";
    std::cout << "2) No.\n";

    std::cout << "Enter your choice: " << std::endl;
    int choice = validate(1,2);

	switch(choice){
		//	add item
		case 1:
		{
			if(container.size() == 3){
                //	print backpack content
                std::cout << "Backpack contents: " << std::endl;

                for(unsigned int i = 0; i < container.size(); i++) {
                    std::cout << "item " << i + 1 << " - " << container[i] << std::endl;
                }

				std::cout << "\nYou already have 3 items. You cannot carry anymore items." << std::endl;
				std::cout << "Would you like to drop the last item?\n" << std::endl;
				std::cout << "1) Yes.\n";
				std::cout << "2) No.\n";

				std::cout << "Enter your choice: " << std::endl;

				int dropItem = validate(1,2);

				switch(dropItem){
					//	You chose to drop the item
					case 1:
					{
						//	container should now have two items
						container.pop_back();
						std::cout << "You dropped the last item and now have enough room to add " << this->getItemName()
						          << "." << std::endl;

						container.push_back(this->getItemName());
						std::cout << "You added " << this->getItemName() << " to your backpack!" << std::endl;
						this->itemTaken = true;
						break;
					}
					//	Do not drop last item
					case 2:
					{
						std::cout << "You chose not to add " << this->getItemName() << " to your backpack." << std::endl;
						break;
					}
				}
			}
			else{
				//	add the item to the backpack
				container.push_back(this->getItemName());
				std::cout << "You added " << this->getItemName() << " to your backpack!" << std::endl;
				this->itemTaken = true;
			}
			break;
		}
		//	do not add item
		case 2:
		{
			std::cout << "You chose not to add " << this->getItemName() << " to your backpack." << std::endl;
			break;
		}	
	}
}
