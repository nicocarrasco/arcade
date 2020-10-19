/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#include "core.hpp"

core::core(const char* lib)
{
    this->displayContentAndGetName();
    this->m_libname = lib;
    m_HandleGame = nullptr;
    m_HandleLib = nullptr;
    m_CurrenLib = m_LoadGraphicalObj.getInstance(lib, &m_HandleLib);
    m_choice[0] = "games/lib_arcade_nibbler.so";
    m_choice[1] = "games/lib_arcade_pacman.so";
}

core::~core()
{

}

void core::displayContentAndGetName()
{
    std::ifstream highscore("highscore_nibbler.txt");
    std::ifstream highscore2("highscore_pacman.txt");
    std::string score;
    std::vector<int> high;
    std::vector<int> high2;
    std::vector<std::pair<int, std::string>> findName;
    std::vector<std::pair<int, std::string>> findName2;
    int i = 0;
    int j = 0;

    while (std::getline(highscore, score)) {
        if (i % 2 == 0)
            high.push_back(std::atoi(score.c_str()));
        else {
            findName.push_back(std::make_pair(high[high.size() - 1], score));
        }
        i += 1;
    }
    std::sort(findName.begin(), findName.end());
    std::reverse(findName.begin(), findName.end());
    highscore.close();
    while (std::getline(highscore2, score)) {
        if (j % 2 == 0)
            high2.push_back(std::atoi(score.c_str()));
        else {
            findName2.push_back(std::make_pair(high2[high2.size() - 1], score));
        }
        j += 1;
    }
    std::sort(findName2.begin(), findName2.end());
    std::reverse(findName2.begin(), findName2.end());
    highscore2.close();
    std::cout << "Welcome to your own Arcade Game !\n\nThe available games are : Nibbler\n";
    std::cout << "                          Pacman\n\n";
    std::cout << "The available libraries are : SFML\n";
    std::cout << "                              SDL\n";
    std::cout << "                              Ncurses\n\n";
    std::cout << "Top 5 Nibbler : \n\n";
    for (int k = 0; k < 5 && k < findName.size(); k += 1) {
        std::cout << findName[k].second << " : " << findName[k].first << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Top 5 Pacman : \n\n";
   for (int k = 0; k < 5 && k < findName2.size(); k += 1) {
        std::cout << findName2[k].second << " : " << findName2[k].first << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Please type your playername : ";
    std::cin >> this->m_name;
    if (std::cin.eof())
        this->m_name = "Player";
}

void core::begin_game()
{
    EVENTS evt = EVENTS::UNKNOWN;
    std::vector<std::string> libname = {"./lib/lib_arcade_sfml.so", "./lib/lib_arcade_sdl.so",  "./lib/lib_arcade_ncurses.so"};
    int idx = 0;
    int idx2 = 0;


    for (; libname[idx].compare(this->m_libname); idx += 1);
    m_Game1 = m_LoadGameObj.getInstance(m_choice[0].c_str(), &m_HandleGame1);
    m_Game2 = m_LoadGameObj.getInstance(m_choice[1].c_str(), &m_HandleGame2);
    m_CurrenLib->init();
    m_Game1->init(m_CurrenLib, m_name);
    m_Game2->init(m_CurrenLib, m_name);
    menu(idx2);
    while (evt != EVENTS::EXIT) {
        evt = m_CurrentGame->start();
        if (evt == EVENTS::NEXTLIB) {
            dlclose(m_HandleLib);
            m_CurrenLib = nullptr;
            m_HandleLib = nullptr;
            idx += 1;
            if (idx == 3)
                idx = 0;
            m_CurrenLib = m_LoadGraphicalObj.getInstance(libname[idx].c_str() , &m_HandleLib);
            this->m_CurrentGame->changeIDisplay(m_CurrenLib);
        }
        if (evt == EVENTS::PREVLIB) {
            dlclose(m_HandleLib);
            m_CurrenLib = nullptr;
            m_HandleLib = nullptr;
            idx -= 1;
            if (idx == -1)
                idx = 2;
            m_CurrenLib = m_LoadGraphicalObj.getInstance(libname[idx].c_str() , &m_HandleLib);
            this->m_CurrentGame->changeIDisplay(m_CurrenLib);
        }
        if (evt == EVENTS::NEXTGAME) {
            idx2 += 1;
            if (idx2 == 2)
                idx2 = 0;
            if (idx2 == 0)
                this->m_CurrentGame = m_Game1;
            if (idx2 == 1)
                this->m_CurrentGame = m_Game2;
            this->m_CurrentGame->changeIDisplay(m_CurrenLib);
        }
        if (evt == EVENTS::PREVGAME) {
            idx2 -= 1;
            if (idx2 == -1)
                idx2 = 1;
            if (idx2 == 0)
                this->m_CurrentGame = m_Game1;
            if (idx2 == 1)
                this->m_CurrentGame = m_Game2;
            this->m_CurrentGame->changeIDisplay(m_CurrenLib);
        }
        if (evt == EVENTS::MENU) {
            menu(idx2);
            this->m_CurrentGame->changeIDisplay(m_CurrenLib);
        }
    }
    dlclose(m_HandleLib);
    dlclose(m_HandleGame1);
    dlclose(m_HandleGame2);
    // if (m_HandleGame || m_HandleLib) {
    //     dlclose(m_HandleGame);
    //     dlclose(m_HandleLib);
    // }
}

void core::menu(int &idx)
{
    switch (m_CurrenLib->menu(m_choice))
    {
        case 0:
            m_CurrentGame = m_Game1;
            idx = 0;
            break;

        case 1:
            m_CurrentGame = m_Game2;
            idx = 1;
            break;
    }
}