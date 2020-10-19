/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entrypoint
*/

#include "pacman.hpp"

IGameModule *Games = nullptr;

__attribute__((constructor))
void init_pacman() {
    Games = new pacman;
}

__attribute__((destructor))
void destroy_pacman() {
    delete Games;
}

extern "C" IGameModule *getModule()
{
    return (Games);
}