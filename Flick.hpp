/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Flick.hpp is the Flick class specification file.
************************************************************************************************/

#ifndef FLICK_HPP
#define FLICK_HPP

#include "Space.hpp"	// #include <string> && #include <vector>


class Flick : public Space{        
    public:
        Flick(std::string m_name, std::string m_action, std::string m_item);
        virtual void action(std::vector<std::string>& container) override;	// override the base class action function
        void findItem(std::vector<std::string>& container);
};

#endif