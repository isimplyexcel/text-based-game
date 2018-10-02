/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Game.hpp is the Game class specification file.
************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include <vector>

class Game
{
    private:
        int steps;      //steps for the game
        Space* caboose;
        Space* bar;
        Space* shopping;
        Space* baggage;
        Space* dining;
        Space* engine;
        Space* location;  //	player location
        std::vector<std::string> container;	//	vector of strings to hold items
        bool hero;
    public:
        Game(); 
        void displayGoal();	//	display goal of the game
        void displaySteps();
        bool checkHero();   //  check to see if container contains hero badge
        void inGameMenu();   // left, right, show backpack
        void printContainer();  //  print the container's items
        void play();    //  play the game
        ~Game(); 

};

#endif