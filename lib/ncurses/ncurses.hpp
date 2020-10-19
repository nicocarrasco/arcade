/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../../include/IDisplayModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <vector>
#include <cstring>
#include <curses.h>
#include <unistd.h>

class ncurses : public IDisplayModule
{
    public:
        ncurses();
        ~ncurses();
        void init() final;
        void display() const override;
        EVENTS getEvent() const override;
        int menu(std::map<int, std::string> list) const override;
        void drawMap(MAPTYPE **map) const override;
        void drawScore(int score, int highscore) const override;
        void closeWindow() override;

    private:
        WINDOW *m_win;
};

extern "C" IDisplayModule *getModule();

#endif /* !ncurses_HPP_ */
