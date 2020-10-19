/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entrypoint
*/

#include "sfml.hpp"

IDisplayModule *libs = nullptr;

__attribute__((constructor))
void init_sfml() {
    libs = new sfml;
}

__attribute__((destructor))
void destroy_sfml() {
    delete libs;
}

extern "C" IDisplayModule *getModule()
{
    return (libs);
}