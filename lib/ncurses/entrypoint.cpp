/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entrypoint
*/

#include "ncurses.hpp"

IDisplayModule *libs = nullptr;

__attribute__((constructor))
void init_ncurses() {
    libs = new ncurses;
}

__attribute__((destructor))
void destroy_ncurses() {
    delete libs;
}

extern "C" IDisplayModule *getModule()
{
    return (libs);
}