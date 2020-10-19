/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entrypoint
*/

#include "sdl.hpp"

IDisplayModule *libs = nullptr;

__attribute__((constructor))
void init_sdl() {
    libs = new sdl;
}

__attribute__((destructor))
void destroy_sdl() {
    delete libs;
}

extern "C" IDisplayModule *getModule()
{
    return (libs);
}