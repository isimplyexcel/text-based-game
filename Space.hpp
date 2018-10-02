/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Space.hpp is the Space class specification file.
************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP 

#include <string>
#include <vector>

class Space
{
    protected:
    	Space* top;	//	will always point to nullptr
        Space* right;	
        Space* bottom;	//	will always point to nullptr
        Space* left;

        bool actionTaken;
        bool itemTaken;
       
        std::string carName;
        std::string actionName;
        std::string itemName;
    public:
        Space(std::string name, std::string action, std::string item);
        void setLeftRight(Space *leftPtr, Space *rightPtr);
        virtual void action(std::vector<std::string>& container) = 0;   //  pure virtual
        Space* getLeft() const;
        Space* getRight() const;
        std::string getCarName() const;	//	returns car name
        std::string getActionName() const;	//	returns action name
        std::string getItemName() const;	//	returns item name
        virtual ~Space() {};	//	Default destructor
};

#endif
