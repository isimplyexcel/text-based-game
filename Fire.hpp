/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Fire.hpp is the Fire class specification file.
************************************************************************************************/

#ifndef FIRE_HPP
#define FIRE_HPP

#include "Space.hpp"	// #include <string> && #include <vector>

class Fire : public Space{
    public:
        Fire(std::string m_name, std::string m_action, std::string m_item);
        virtual void action(std::vector<std::string>& container) override;	// override the base class action function
        void findItem(std::vector<std::string>& container);
};

#endif