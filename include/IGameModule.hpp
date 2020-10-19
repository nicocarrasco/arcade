/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <dlfcn.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "IDisplayModule.hpp"

class IGameModule {
    public:
        virtual ~IGameModule () = default;
        virtual void init (IDisplayModule *display, std::string const& name) = 0;
        virtual EVENTS start() = 0;
        virtual void changeIDisplay (IDisplayModule *display) = 0;

    protected:
    private:
};

#endif /* !IGAMEMODULE_HPP_ */