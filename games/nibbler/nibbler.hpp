/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../../include/IGameModule.hpp"
#include "../../include/IDisplayModule.hpp"
#include <cstring>
#include <vector>
#include <chrono>
#include <ctime>

class nibbler : public IGameModule
{
    private:
        typedef struct cell {
            int x;
            int y;
        }cell;
        std::vector<cell> m_snake;
        cell m_fruit;
        int m_score;
        int m_highscore;
        IDisplayModule *m_display;
        DIRECTION m_dir;
        MAPTYPE **m_map;
        EVENTS m_evt;
        DIRECTION m_tmp;
        std::chrono::system_clock::time_point m_timer;
        std::string m_name;

    public:
        nibbler();
        ~nibbler();
        void init(IDisplayModule *display, std::string const& name);
        EVENTS start() override;
        void insertSnakeInMap();
        void moveAutoSnake();
        void checkFruit(cell const&);
        bool isCollision();
        void restartSnake();
        void changeIDisplay (IDisplayModule *display) override;
        int getHighScore();
};

extern "C" IGameModule *getModule();

#endif /* !NIBBLER_HPP_ */
