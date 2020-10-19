/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include "enum.hpp"
#include <map>

class IDisplayModule {
    public:
        virtual ~IDisplayModule () = default;
        virtual void init () = 0;
        virtual void display() const = 0;
        virtual EVENTS getEvent() const = 0;
        virtual int menu(std::map<int, std::string> list) const = 0;
        virtual void drawMap(MAPTYPE **map) const = 0;
        virtual void drawScore(int score, int highscore) const = 0;
        virtual void closeWindow() = 0;

    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
