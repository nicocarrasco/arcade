/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "core/core.hpp"

int main(int ac, char**av)
{
    try {
        if (ac != 2)
            throw error("Error: invalid nbr of arg");
    }
    catch (error const& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    std::vector<std::string> libname = {"./lib/lib_arcade_sfml.so", "./lib/lib_arcade_sdl.so",  "./lib/lib_arcade_ncurses.so"};
    int i = 0;

    for (;i < 3 && std::strcmp(libname[i].c_str(), av[1]); i += 1);
    if (i == 3) {
        return (84);
    }
    core Arcade(av[1]);
    Arcade.begin_game();

    return (0);
}