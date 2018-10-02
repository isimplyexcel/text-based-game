/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/10/18
** Description: validate.cpp is the implementation file for the validate function
************************************************************************************************/
#include "validate.hpp"
#include <iostream>

/************************************************************************************************
                                    validate(int min, int max)
    This function checks to see if the user input is an intger that is in the range between 
min and max.
*************************************************************************************************/
int validate(int min, int max) {
    int choice;
    bool isValid = false;
    do {
        std::cin >> choice;

        if(!std::cin.fail() && (choice >= min && choice <= max)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
            std::cout << "Invalid input. Please try again: " << std::endl;
                      //<< min << " and " << max << ": " << std::endl;
        }
    } while(!isValid);

    return choice;
}