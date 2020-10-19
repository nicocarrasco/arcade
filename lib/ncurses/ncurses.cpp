/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ncurses
*/

#include "ncurses.hpp"

ncurses::ncurses()
{
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    start_color();
    init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
    init_pair(ITEM, COLOR_GREEN, COLOR_GREEN);
    init_pair(SNAKE, COLOR_RED, COLOR_RED);
    init_pair(PACMAN, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(PACGUM, 0, COLOR_YELLOW);
    init_pair(MEGAPACGUM, 0, COLOR_YELLOW);
    init_pair(BLINKY, COLOR_CYAN, COLOR_CYAN);
    init_pair(PINKY, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(INKY, COLOR_GREEN, COLOR_GREEN);
    init_pair(CLYDE, COLOR_RED, COLOR_RED);
    init_pair(FLEEGHOST, COLOR_BLUE, COLOR_BLUE);
    init_pair(DEADGHOST, COLOR_WHITE, COLOR_WHITE);
    keypad(stdscr, true);
    wtimeout(stdscr, 10);
}

ncurses::~ncurses()
{
}

void ncurses::init()
{
    return;
}

void ncurses::display() const
{
    refresh();
    timeout(6);
}

EVENTS ncurses::getEvent() const
{
    int ch = getch();
    switch (ch) {
        case 27:
            return (EVENTS::EXIT);
        case KEY_UP:
            return (EVENTS::UP);
        case KEY_DOWN:
            return (EVENTS::DOWN);
        case KEY_LEFT:
            return (EVENTS::LEFT);
        case KEY_RIGHT:
            return (EVENTS::RIGHT);
            case 110:
            return (EVENTS::NEXTLIB);
            case 112:
            return (EVENTS::PREVLIB);
            case 97:
            return (EVENTS::PREVGAME);
            case 122:
            return (EVENTS::NEXTGAME);
            case 109:
            return (EVENTS::MENU);
            case 114:
            return (EVENTS::RESTART);
        default:
            this->display();
            return (EVENTS::UNKNOWN);
    }
}

int ncurses::menu(std::map<int, std::string> list) const
{
    int maxX, maxY;
    int highlight = 0;
    int choice;
    getmaxyx(stdscr, maxY, maxX);
    WINDOW *menuwin = newwin(10, maxX / 2, (maxY - 10) / 2, (maxX - (maxX / 2)) / 2);
    box(menuwin, 0, 0);
    refresh();
    getmaxyx(menuwin, maxY, maxX);
    keypad(menuwin, TRUE);

    while (1) {
        for (int i = 0; i < 2; i += 1) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            if (i == 0)
                mvwprintw(menuwin, i + (maxY - 1.5) / 2, (maxX - (maxX / 2)) / 2, "Nibbler");
            if (i == 1)
                mvwprintw(menuwin, i + (maxY - 1.5) / 2, (maxX - (maxX / 2)) / 2, "Pacman");
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        switch (choice) {
            case KEY_UP:
                highlight =- 1;
                if (highlight == -1)
                    highlight = 0;
            break;

            case KEY_DOWN:
                highlight += 1;
                if (highlight == 2)
                    highlight = 1;
            break;
            case '\n':
                delwin(menuwin);
                return highlight;
            default:
                break;
        }
    }
}

void ncurses::drawMap(MAPTYPE **map) const
{
    clear();
    for (int i = 0; i < 25; i += 1) {
        for (int j = 0; j < 30; j += 1) {
            bool ismove = false;
            if (map[i * 25][j * 30] == WALL) {
                attron(COLOR_PAIR(WALL));
                waddch(stdscr,( 'W' | A_STANDOUT));
                attroff(COLOR_PAIR(WALL));
            }
            if (map[i * 25][j * 30] == ITEM) {
                attron(COLOR_PAIR(ITEM));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(ITEM));
            }
            if (map[i * 25][j * 30] == SNAKE) {
                attron(COLOR_PAIR(SNAKE));
                waddch(stdscr, 'C' | A_STANDOUT);
                attroff(COLOR_PAIR(SNAKE));
            }
            if (map[i * 25][j * 30] == SNAKE_HEAD) {
                attron(COLOR_PAIR(SNAKE));
                waddch(stdscr, 'C' | A_STANDOUT);
                attroff(COLOR_PAIR(SNAKE));
            }
            for (int k = 0; k < 12; k += 1) {
                for (int m = 0; m < 15; m += 1) {
            if (map[i * 25 + k][j * 30 + m] == PACMAN) {
                attron(COLOR_PAIR(PACMAN));
                waddch(stdscr, 'C' | A_STANDOUT);
                attroff(COLOR_PAIR(PACMAN));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == BLINKY) {
                attron(COLOR_PAIR(BLINKY));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(BLINKY));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == PINKY) {
                attron(COLOR_PAIR(PINKY));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(PINKY));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == INKY) {
                attron(COLOR_PAIR(INKY));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(INKY));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == CLYDE) {
                attron(COLOR_PAIR(CLYDE));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(CLYDE));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == FLEEGHOST) {
                attron(COLOR_PAIR(FLEEGHOST));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(FLEEGHOST));
                ismove = true;
                k = 12;
                m = 15;
            }
            else if (map[i * 25 + k][j * 30 + m] == DEADGHOST) {
                attron(COLOR_PAIR(DEADGHOST));
                waddch(stdscr, '@' | A_STANDOUT);
                attroff(COLOR_PAIR(DEADGHOST));
                ismove = true;
                k = 12;
                m = 15;
            }
        }
    }
            if (map[i * 25][j * 30] == EMPTY && !(i != 0 && j != 0 && map[i * 25 + 10][j * 30 + 12] == PACGUM)
            && !(map[i * 25 + 3][j * 30 + 6] == MEGAPACGUM) && !ismove) {
                waddch(stdscr, ' ');
            }
            if (i != 0 && j != 0 && map[i * 25 + 10][j * 30 + 12] == PACGUM &&
            !(map[i * 25 + 3][j * 30 + 6] == MEGAPACGUM)  && !ismove) {
                attron(COLOR_PAIR(PACGUM));
                waddch(stdscr, '*' | A_STANDOUT);
                attroff(COLOR_PAIR(PACGUM));
            }
            if (i != 0 && j != 0 && map[i * 25 + 3][j * 30 + 6] == MEGAPACGUM && !ismove) {
                attron(COLOR_PAIR(MEGAPACGUM));
                waddch(stdscr, 'O' | A_STANDOUT);
                attroff(COLOR_PAIR(MEGAPACGUM));
            }
        }
        wprintw(stdscr, "\n");
    }
}

void ncurses::drawScore(int score, int highscore) const
{
    WINDOW *w_score = subwin(stdscr, 0, 0, 0, (LINES / 2) + 9);
    std::string s = "Score : ";

    s.append(std::to_string(score));
    mvwprintw(w_score, 1, 1, s.c_str());
    wrefresh(w_score);
    delwin(w_score);
}

void ncurses::closeWindow()
{
    clear();
    curs_set(1);
    echo();
    reset_shell_mode();
}