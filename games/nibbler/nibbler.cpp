/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
    m_score = 0;
}

nibbler::~nibbler()
{
    if (this->m_map) {
        for (int i = 0; i < 25 * 25; i += 1) {
            delete this->m_map[i];
        }
        delete this->m_map;
    }
}

void nibbler::init(IDisplayModule *display, std::string const& name)
{
    this->m_name = name;
    this->m_display = display;
    this->m_dir = DIRECTION::DIR_BACKWARD;
    this->m_map = new MAPTYPE*[25 * 25];
    for (int i = 0; i < 25 * 25; i += 1) {
        this->m_map[i] = new MAPTYPE[900];
        for (int j = 0; j < 30 * 30; j += 1) {
            if (j == 0 || j == 1 * 30 ||  j == 29 * 30 ||  j == 28 * 30 || i == 0 || i == 1 * 25|| i == 24 * 25
            || i == 23 * 25)
                this->m_map[i][j] = WALL;
            else
                this->m_map[i][j] = EMPTY;
        }
    }
    this->m_snake.push_back({15 * 30,13 * 25});
    this->m_snake.push_back({15 * 30,12 * 25});
    this->m_snake.push_back({15 * 30,11 * 25});
    this->m_snake.push_back({15 * 30,10 * 25});
    this->m_fruit.x = (rand() % (28 - 2) + 2) * 30;
    this->m_fruit.y = (rand() % (23 - 2) + 2) * 25;
    this->m_timer = std::chrono::system_clock::now() + std::chrono::milliseconds(190);
    this->m_highscore = this->getHighScore();
}

int nibbler::getHighScore()
{
    std::ifstream highscore("highscore_nibbler.txt");
    std::string score;
    std::vector<int> high;
    int i = 0;

    while (std::getline(highscore, score)) {
        if (i % 2 == 0)
            high.push_back(std::atoi(score.c_str()));
        i += 1;
    }
    highscore.close();
    std::sort(high.begin(), high.end());
    std::reverse(high.begin(), high.end());
    return (high[0]);
}

void nibbler::checkFruit(cell const& newCell)
{
    if (this->m_snake[0].x == this->m_fruit.x &&
    this->m_snake[0].y == this->m_fruit.y) {
        this->m_snake.push_back({newCell.x, newCell.y});
        this->m_map[this->m_fruit.y][this->m_fruit.x] = EMPTY;
        this->m_fruit.x = (rand() % (28 - 2) + 2) * 30;
        this->m_fruit.y = (rand() % (23 - 2) + 2) * 25;
        m_score += 1;
    }
}

void nibbler::moveAutoSnake()
{
    this->m_map[this->m_snake[this->m_snake.size() - 1].y][this->m_snake[this->m_snake.size() - 1].x] = EMPTY;
    for (int i = this->m_snake.size(); i > 0; i -= 1) {
        this->m_snake[i].y = this->m_snake[i - 1].y;
        this->m_snake[i].x = this->m_snake[i - 1].x;
    }
    if (this->m_dir == DIR_FORWARD)
        this->m_snake[0].y -= 1 * 25;
    else if (this->m_dir == DIR_BACKWARD)
        this->m_snake[0].y += 1 * 25;
    else if (this->m_dir == DIR_RIGHT)
        this->m_snake[0].x += 1 * 30;
    else if (this->m_dir == DIR_LEFT)
        this->m_snake[0].x -= 1 * 30;
}

void nibbler::insertSnakeInMap()
{
    this->m_map[this->m_snake[0].y][this->m_snake[0].x] = SNAKE_HEAD;
    for (int i = 1; i < this->m_snake.size(); i += 1)
        this->m_map[this->m_snake[i].y][this->m_snake[i].x] = SNAKE;
    this->m_map[this->m_fruit.y][this->m_fruit.x] = ITEM;
}

bool nibbler::isCollision()
{
    if (this->m_snake[0].x == 0 || this->m_snake[0].x == 29 * 30
    || this->m_snake[0].y == 0 || this->m_snake[0].y == 24 * 25 ||
    this->m_snake[0].x == 1 * 30 || this->m_snake[0].x == 28 * 30
    || this->m_snake[0].y == 1 * 25 || this->m_snake[0].y == 23 * 25)
        return (true);
    for (int i = 1; i < this->m_snake.size(); i += 1)
        if (this->m_snake[0].x == this->m_snake[i].x
        && this->m_snake[0].y == this->m_snake[i].y)
            return (true);
    return (false);
}

void nibbler::restartSnake()
{
    this->m_dir = DIR_BACKWARD;
    while (this->m_snake.size() > 0) {
        if ((this->m_snake.size() == 1 && !(this->m_snake[0].x == 0 || this->m_snake[0].x == 29 * 30
        || this->m_snake[0].y == 0 || this->m_snake[0].y == 24 * 25 ||
        this->m_snake[0].x == 1 * 30 || this->m_snake[0].x == 28 * 30
        || this->m_snake[0].y == 1 * 25 || this->m_snake[0].y == 23 * 25))
        || this->m_snake.size() > 1)
            this->m_map[this->m_snake[this->m_snake.size() - 1].y][this->m_snake[this->m_snake.size() - 1].x] = EMPTY;
        this->m_snake.pop_back();
    }
    this->m_map[this->m_fruit.y][this->m_fruit.x] = EMPTY;
    m_score = 0;
    this->m_snake.push_back({15 * 30,13 * 25});
    this->m_snake.push_back({15 * 30,12 * 25});
    this->m_snake.push_back({15 * 30,11 * 25});
    this->m_snake.push_back({15 * 30,10 * 25});
    this->m_fruit.x = (rand() % (28 - 2) + 2) * 30;
    this->m_fruit.y = (rand() % (23 - 2) + 2) * 25;
    this->m_highscore = this->getHighScore();
}

EVENTS nibbler::start()
{
    this->m_evt = EVENTS::UNKNOWN;
    while ((this->m_evt = this->m_display->getEvent()) != EVENTS::EXIT
    && this->m_evt != EVENTS::NEXTLIB && this->m_evt != EVENTS::PREVLIB
    && this->m_evt != EVENTS::NEXTGAME && this->m_evt != EVENTS::PREVGAME
    && this->m_evt != EVENTS::MENU) {
        if (this->m_evt == EVENTS::UP)
            this->m_tmp = DIR_FORWARD;
        else if (this->m_evt == EVENTS::DOWN)
            this->m_tmp = DIR_BACKWARD;
        else if (this->m_evt == EVENTS::LEFT)
            this->m_tmp = DIR_LEFT;
        else if (this->m_evt == EVENTS::RIGHT)
            this->m_tmp = DIR_RIGHT;
        else if (this->m_evt == EVENTS::RESTART)
            this->restartSnake();
        if (std::chrono::system_clock::now() > this->m_timer) {
            if (this->m_tmp == DIR_FORWARD && this->m_dir != DIR_BACKWARD)
                this->m_dir = this->m_tmp;
            else if (this->m_tmp == DIR_BACKWARD && this->m_dir != DIR_FORWARD)
                this->m_dir = this->m_tmp;
            else if (this->m_tmp == DIR_LEFT && this->m_dir != DIR_RIGHT)
                this->m_dir = this->m_tmp;
            else if (this->m_tmp == DIR_RIGHT && this->m_dir != DIR_LEFT)
                this->m_dir = this->m_tmp;
            cell newCell = {this->m_snake[this->m_snake.size() - 1].x, this->m_snake[this->m_snake.size() - 1].y};
            this->moveAutoSnake();
            this->checkFruit(newCell);
            if (this->isCollision()) {
                std::ofstream highscore;
                highscore.open ("highscore_nibbler.txt", std::ios_base::app);
                highscore << m_score << std::endl << m_name << std::endl;
                highscore.close();
                this->restartSnake();
            }
            this->insertSnakeInMap();
            this->m_timer = std::chrono::system_clock::now() + std::chrono::milliseconds(190);
        }
        this->m_display->drawMap(this->m_map);
        m_display->drawScore(m_score, m_highscore);
        this->m_display->display();
    }
    if (this->m_evt == EVENTS::EXIT
    || this->m_evt == EVENTS::NEXTLIB || this->m_evt == EVENTS::PREVLIB)
        this->m_display->closeWindow();
    if (this->m_evt == EVENTS::EXIT) {
    std::ofstream highscore;
        highscore.open ("highscore_nibbler.txt", std::ios_base::app);
        highscore << m_score << std::endl << m_name << std::endl;
        highscore.close();
    }
    return (this->m_evt);
}

void nibbler::changeIDisplay (IDisplayModule *display)
{
    this->m_display = display;
}