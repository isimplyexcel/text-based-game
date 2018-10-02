/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Space.cpp is the Space class implementation file.
************************************************************************************************/

#include "Space.hpp"
#include "validate.hpp"

#include <iostream>

/***********************************************************************************************
			Space::Space(std::string carName, std::string action, std::string item)
This is the constructor. It has 3 string parameters. It sets the name of the car, the name
of the action, and the name of the item. 
************************************************************************************************/
Space::Space(std::string m_name, std::string m_action, std::string m_item){
	this->carName = m_name;
	this->actionName = m_action;
	this->itemName = m_item;
	this->actionTaken = false;
	this->itemTaken = false;
	this->top = nullptr;
	this->bottom = nullptr;
}



/***********************************************************************************************
								void Space::setLeftRight()
			This function sets the left and right space pointers of the cars. 
************************************************************************************************/
void Space::setLeftRight(Space* leftPtr, Space* rightPtr){
	this->left = leftPtr;
	this->right = rightPtr;
}



/***********************************************************************************************
								Space* Space::getLeft()
						This function returns the left pointer
************************************************************************************************/
Space* Space::getLeft() const{
	return left;
}


/***********************************************************************************************
								Space* Space::getRight()
						This function returns the right pointer
************************************************************************************************/
Space* Space::getRight() const{
	return right;
}



/***********************************************************************************************
								std::string Space::getCarName()
						This function returns the name of the Car
************************************************************************************************/
std::string Space::getCarName() const{
	return carName;
}



/***********************************************************************************************
								std::string Space::getActionName()
						This function returns the name of the action
************************************************************************************************/
std::string Space::getActionName() const{
	return actionName;
}



/***********************************************************************************************
								std::string Space::getItemName()
						This function returns the name of the item
************************************************************************************************/
std::string Space::getItemName() const{
	return itemName;
}