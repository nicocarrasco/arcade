/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "../../include/IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class sdl : public IDisplayModule
{
    public:
        sdl();
        ~sdl();
        void init() final;
        void display() const override;
        EVENTS getEvent() const override;
        int menu(std::map<int, std::string> list) const override;
        void drawMap(MAPTYPE **map) const override;
        void drawScore(int score,  int highscore) const override;
        void closeWindow() override;

    private:
        SDL_Window *m_window;
        SDL_Renderer* m_renderer;
        SDL_Rect *m_game;
        SDL_Rect *m_game2;
        SDL_Rect *m_game3;
        SDL_Rect *m_game4;
        TTF_Font *m_font;
        SDL_Color *m_White;
        SDL_Color *m_Red;
        SDL_Surface *m_Surface;
};

extern "C" IDisplayModule *getModule();

#endif /* !SDL_HPP_ */
