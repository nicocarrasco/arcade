/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../include/IDisplayModule.hpp"
#include "../include/IGameModule.hpp"
#include "../include/DLLoader.hpp"
#include "../error/error.hpp"
#include <vector>
#include <map>
#include <cstring>
#include <unordered_map>
#include <utility>

class core
{
    public:
        core(const char *lib);
        ~core();
        void begin_game();
        void menu(int &idx);
        void displayContentAndGetName();

    private:
        DLLoader<IDisplayModule> m_LoadGraphicalObj;
        DLLoader<IGameModule> m_LoadGameObj;
        IDisplayModule * m_CurrenLib;
        IGameModule * m_CurrentGame;
        IGameModule * m_Game1;
        IGameModule * m_Game2;
        void *m_HandleLib;
        void *m_HandleGame;
        void *m_HandleGame1;
        void *m_HandleGame2;
        std::map<int, std::string> m_choice;
        std::string m_libname;
        std::string m_name;
};

#endif /* !CORE_HPP_ */