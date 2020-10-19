/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../include/IGameModule.hpp"
#include "../../include/IDisplayModule.hpp"
#include <cstring>
#include <vector>
#include <chrono>
#include <ctime>

class pacman : public IGameModule
{
        private:
        typedef struct cell {
            int x;
            int y;
        }cell;
        cell m_pacman;
        bool isAlive;
        std::vector<cell> m_ghosts;
        std::vector<std::chrono::system_clock::time_point> m_ghostTimer;
        std::vector<std::chrono::system_clock::time_point> m_ghostFleeTimer;
        std::vector<bool> m_ghostInBase;
        std::vector<bool> m_ghostIsAlive;
        std::vector<DIRECTION> m_ghostDir;
        std::vector<unsigned int> m_ghostIntel;
        IDisplayModule *m_display;
        DIRECTION m_dir;
        MAPTYPE **m_map;
        int m_nbPacgum;
        int m_difficulty;
        int m_score;
        EVENTS m_evt;
        DIRECTION m_tmp;
        DIRECTION m_oldDir;
        std::chrono::system_clock::time_point m_timer;
        int m_highscore;
        std::string m_name;
        bool m_isStarted;
        int m_speed;
        std::chrono::system_clock::time_point m_speedTimer;

    public:
        pacman();
        ~pacman();
        void init(IDisplayModule *display, std::string const& name);
        void stop();
        EVENTS start() override;
        void insertPacmanInMap();
        void moveAutoPacman(DIRECTION &oldDir, DIRECTION &tmp);
        void moveAutoGhosts();
        void makeGoodMove(int idx, cell &old, cell target);
        void makeDumbMove(int idx, cell &old);
        void chasePacman(int index);
        void flee(int idx);
        bool checkWall(int y, int x, DIRECTION dir);
        void checkPacgum();
        void move(DIRECTION dir, cell &cell);
        void goOutBase(int idx);
        void goToBase(int idx);
        void ghostBeginToFlee();
        bool checkPacman(int y, int x, DIRECTION dir);
        bool checkGhost(int y, int x, DIRECTION dir);
        void restartPacman(bool incDif);
        void changeIDisplay (IDisplayModule *display) override;
        int getHighScore();
};

extern "C" IGameModule *getModule();

#endif /* !PACMAN_HPP_ */