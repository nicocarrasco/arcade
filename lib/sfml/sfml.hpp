/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../../include/IDisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class sfml : public IDisplayModule
{
public:
    sfml();
    ~sfml();
    void init() final;
    void display() const override;
    EVENTS getEvent() const override;
    int menu(std::map<int, std::string> list) const override;
    void drawMap(MAPTYPE **map) const override;
    void drawScore(int score, int highscore) const override;
    void closeWindow() override;

private:
    sf::RenderWindow *m_window;
    sf::RectangleShape *m_wall;
    sf::Texture *t_character;
    sf::Sprite *s_character;
    sf::Texture *t_megapacgum;
    sf::Sprite *s_megapacgum;
    sf::Texture *t_fruit;
    sf::Sprite *s_fruit;
    sf::Texture *t_snake;
    sf::Sprite *s_snake;
    sf::Texture *t_hsnake;
    sf::Sprite *s_hsnake;
    sf::Texture *t_clyde;
    sf::Sprite *s_clyde;
    sf::Texture *t_blinky;
    sf::Sprite *s_blinky;
    sf::Texture *t_pinky;
    sf::Sprite *s_pinky;
    sf::Texture *t_inky;
    sf::Sprite *s_inky;
    sf::Texture *t_fleeGhost;
    sf::Sprite *s_fleeGhost;
    sf::Texture *t_eyeGhost;
    sf::Sprite *s_eyeGhost;
    sf::CircleShape *m_pacgum;
    sf::Font *font;
    sf::Text *m_Game[2];
    sf::Clock *_clock;
    sf::IntRect *_rect_ch;
    sf::IntRect *_rect_Ghost;

};

extern "C" IDisplayModule *getModule();

#endif /* !SFML_HPP_ */
