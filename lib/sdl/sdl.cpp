/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sdl
*/

#include "sdl.hpp"

sdl::sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    m_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 900, 625, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit (1);
    }
    m_renderer =  SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_game = new SDL_Rect;
    m_game->w = 30;
    m_game->h = 25;
    m_game2 = new SDL_Rect;
    m_game2->w = 6;
    m_game2->h = 6;
    m_game3 = new SDL_Rect;
    m_game3->w = 8;
    m_game3->h = 8;
    m_game4 = new SDL_Rect;
    m_game4->w = 18;
    m_game4->h = 18;
    this->m_font = TTF_OpenFont("lib/sdl/Asset/Font/arial.ttf", 18);
}

sdl::~sdl()
{
}

void sdl::init()
{
}

void sdl::display() const
{
    SDL_RenderPresent(m_renderer);
}

EVENTS sdl::getEvent() const
{
    SDL_Event event;

    SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                return (EVENTS::EXIT);
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        return (EVENTS::EXIT);
                    case SDLK_UP:
                        return (EVENTS::UP);
                    case SDLK_DOWN:
                        return (EVENTS::DOWN);
                    case SDLK_RIGHT:
                        return (EVENTS::RIGHT);
                    case SDLK_LEFT:
                        return (EVENTS::LEFT);
                    case SDLK_n:
                        return (EVENTS::NEXTLIB);
                    case SDLK_p:
                        return (EVENTS::PREVLIB);
                    case SDLK_a:
                        return (EVENTS::PREVGAME);
                    case SDLK_z:
                        return (EVENTS::NEXTGAME);
                    case SDLK_m:
                        return (EVENTS::MENU);
                    case SDLK_r:
                        return (EVENTS::RESTART);
                    default:
                        break;
                }
            break;
        }
    return (EVENTS::UNKNOWN);
}

int sdl::menu(std::map<int, std::string> list) const
{
    std::string game[2] = {"Nibbler", "Pacman"};
    SDL_Color white = {255, 255, 255};
    SDL_Color red = {255, 0, 0};
    SDL_Surface* surf = TTF_RenderText_Solid(this->m_font, game[0].c_str(), red);
    SDL_Texture* msg = SDL_CreateTextureFromSurface(this->m_renderer, surf);
    surf = TTF_RenderText_Solid(this->m_font, game[1].c_str(), white);
    SDL_Texture* msg1 = SDL_CreateTextureFromSurface(this->m_renderer, surf);
    int w = 500;
    int h = 50;
    SDL_Rect rec = { (900 / 2) / 2, 625 / (2 + 1) * 1, w, h };
    SDL_Rect rec1 = {(900 / 2) / 2, 625 / (2 + 1) * 2, w, h};
    SDL_Event event;
    int choice = 0;
    int menu = 1;

    while (menu == 1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_RETURN:
                            menu = 0;
                        break;
                        case SDLK_UP:
                            if (choice - 1 >= 0) {
                                surf = TTF_RenderText_Solid(this->m_font, game[choice].c_str(), white);
                                msg1 = SDL_CreateTextureFromSurface(this->m_renderer, surf);
                                choice -= 1;
                                surf = TTF_RenderText_Solid(this->m_font, game[choice].c_str(), red);
                                msg = SDL_CreateTextureFromSurface(this->m_renderer, surf);
                            }
                        break;
                        case SDLK_DOWN:
                            if (choice + 1 < 2) {
                                surf = TTF_RenderText_Solid(this->m_font, game[choice].c_str(), white);
                                msg = SDL_CreateTextureFromSurface(this->m_renderer, surf);
                                choice += 1;
                                surf = TTF_RenderText_Solid(this->m_font, game[choice].c_str(), red);
                                msg1 = SDL_CreateTextureFromSurface(this->m_renderer, surf);
                            }
                        break;
                        default:
                            break;
                    }
                break;
            }
        }
        SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        for (int i = 0; i < 2; i += 1) {
            if (i == 0) {
                SDL_QueryTexture(msg, NULL, NULL, &w, &h);
                SDL_RenderCopy(this->m_renderer, msg, NULL, &rec);
            } else {
                SDL_QueryTexture(msg1, NULL, NULL, &w, &h);
                SDL_RenderCopy(this->m_renderer, msg1, NULL, &rec1);
            }
        }
        display();
    }
    return (choice);
}

void sdl::drawMap(MAPTYPE **map) const
{
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    for (int i = 0; i < 625; i += 1) {
        for (int j = 0; j < 900; j += 1) {
            if (map[i][j] == PACGUM) {
                SDL_SetRenderDrawColor(m_renderer, 251, 255, 0, 0);
                m_game2->x = j;
                m_game2->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game2));
            }
            else if (map[i][j] == MEGAPACGUM) {
                SDL_SetRenderDrawColor(m_renderer, 251, 255, 0, 0);
                m_game4->x = j;
                m_game4->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game4));
            }
        }
    }
    for (int i = 0; i < 625; i += 1) {
        for (int j = 0; j < 900; j += 1) {
            if (map[i][j] == WALL) {
                SDL_SetRenderDrawColor( m_renderer, 0, 12, 255, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == SNAKE_HEAD) {
                SDL_SetRenderDrawColor(m_renderer, 251, 255, 0, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == SNAKE) {
                SDL_SetRenderDrawColor(m_renderer, 251, 255, 0, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == PACMAN) {
                SDL_SetRenderDrawColor(m_renderer, 251, 255, 0, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == ITEM) {
                SDL_SetRenderDrawColor( m_renderer, 0, 255, 255, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == BLINKY) {
                SDL_SetRenderDrawColor( m_renderer, 255, 0, 0, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == PINKY) {
                SDL_SetRenderDrawColor( m_renderer, 255, 0, 228, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == INKY) {
                SDL_SetRenderDrawColor( m_renderer, 0, 255, 255, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == CLYDE) {
                SDL_SetRenderDrawColor( m_renderer, 35, 255, 0, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == FLEEGHOST) {
                SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 0);
                m_game->x = j;
                m_game->y = i;
                SDL_RenderFillRect(m_renderer, &(*m_game));
            }
            else if (map[i][j] == DEADGHOST) {
                SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 0);
                m_game3->x = j + 7;
                m_game3->y = i + 6;
                SDL_RenderFillRect(m_renderer, &(*m_game3));
                SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 0);
                m_game3->x = j + 19;
                m_game3->y = i + 6;
                SDL_RenderFillRect(m_renderer, &(*m_game3));
            }
        }
    }
}

void sdl::drawScore(int score,  int highscore) const
{
    std::string s_score("Score : ");
    s_score += std::to_string(score);
    SDL_Color white = {255, 255, 255};
    SDL_Surface* surf = TTF_RenderText_Solid(this->m_font, s_score.c_str(), white);
    SDL_Texture* msg = SDL_CreateTextureFromSurface(this->m_renderer, surf);
    int w = 0;
    int h = 0;
    SDL_QueryTexture(msg, NULL, NULL, &w, &h);
    SDL_Rect rec = { 0, 0, w, h };
    SDL_RenderCopy(this->m_renderer, msg, NULL, &rec);

    std::string s_highscore("High Score : ");
    s_highscore += std::to_string(highscore);
    SDL_Surface* surf2 = TTF_RenderText_Solid(this->m_font, s_highscore.c_str(), white);
    SDL_Texture* msg2 = SDL_CreateTextureFromSurface(this->m_renderer, surf2);
    int w2 = 0;
    int h2 = 0;
    SDL_QueryTexture(msg2, NULL, NULL, &w2, &h2);
    SDL_Rect rec2 = { 0, 30, w2, h2 };
    SDL_RenderCopy(this->m_renderer, msg2, NULL, &rec2);
}

void sdl::closeWindow()
{
    TTF_CloseFont(m_font);
    SDL_DestroyWindow(m_window);
    TTF_Quit();
    SDL_Quit();
}