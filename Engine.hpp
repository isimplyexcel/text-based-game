/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: Engine.hpp is the Engine class specification file.
************************************************************************************************/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Space.hpp"	// #include <string> && #include <vector>


class Engine : public Space{

    public:
        Engine(std::string m_name, std::string m_action, std::string m_item);
        virtual void action(std::vector<std::string>& container) override;	// override the base class action function
        void findItem(std::vector<std::string>& container);
        bool checkKey(std::vector<std::string>& container, std::string search);
};

#endif