/*
** EPITECH PROJECT, 2020
** yo
** File description:
** enum
*/

#ifndef ENUM_HPP_
#define ENUM_HPP_

enum EVENTS
{
    PREVLIB,
    NEXTLIB,
    PREVGAME,
    NEXTGAME,
    RESTART,
    MENU,
    EXIT,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    UNKNOWN
};

enum MAPTYPE
{
    EMPTY,
    WALL,
    SNAKE,
    SNAKE_HEAD,
    ITEM,
    POINT,
    ENNEMY,
    MEGAPACGUM,
    PACMAN,
    PACGUM,
    BLINKY,
    PINKY,
    INKY,
    CLYDE,
    FLEEGHOST,
    DEADGHOST
};

enum DIRECTION
{
    DIR_FORWARD,
    DIR_LEFT,
    DIR_BACKWARD,
    DIR_RIGHT,
    DIR_UNKNOWN
};

#endif /* !ENUM_HPP_ */
