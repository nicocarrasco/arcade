/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entrypoint
*/

#include "nibbler.hpp"

IGameModule *Games = nullptr;

__attribute__((constructor))
void init_nibbler() {
    Games = new nibbler;
}

__attribute__((destructor))
void destroy_nibbler() {
    // delete Games;
}

extern "C" IGameModule *getModule()
{
    return (Games);
}