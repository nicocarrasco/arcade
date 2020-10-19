/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#include "pacman.hpp"

pacman::pacman()
{
}

pacman::~pacman()
{
    if (this->m_map) {
        for (int i = 0; i < 25 * 25; i += 1) {
            delete this->m_map[i];
        }
        delete this->m_map;
    }
}

void pacman::changeIDisplay(IDisplayModule *display)
{
    this->m_display = display;
}

void pacman::init(IDisplayModule *display, std::string const& name)
{
    this->m_name = name;
    this->m_display = display;
    this->m_dir = DIRECTION::DIR_FORWARD;
    srand(time(NULL));
    this->m_map = new MAPTYPE*[25 * 25];
    for (int i = 0; i < 25 * 25; i += 1) {
        this->m_map[i] = new MAPTYPE[30 * 30];
        for (int j = 0; j < 30 * 30; j += 1) {
            if ((i == 25 * 0 && j >= 30 * 4 && j <= 30 * 24) || (i == 25 * 24 && j >= 30 * 4 && j <= 30 * 24)
            || (j == 30 * 12 && i >= 25 * 10 && i <= 25 * 13)
            || (j == 30 * 16 && i >= 25 * 10 && i <= 25 * 13)
            || (i == 25 * 10 && j >= 30 * 12 && j <= 30 * 16)
            || (i == 25 * 13 && j >= 30 * 12 && j <= 30 * 16)
            || (i == 25 * 15 && j >= 30 * 12 && j <= 30 * 16)
            || (j == 30 * 14 && i >= 25 * 16 && i <= 25 * 17)
            || (i == 25 * 19 && j >= 30 * 12 && j <= 30 * 16)
            || (i == 25 * 20 && j >= 30 * 12 && j <= 30 * 16)
            || (j == 30 * 14 && i >= 25 * 20 && i <= 25 * 22)
            || (i == 25 * 17 && j >= 30 * 6 && j <= 30 * 8)
            || (i == 25 * 17 && j >= 30 * 10 && j <= 30 * 12)
            || (i == 25 * 17 && j >= 30 * 16 && j <= 30 * 18)
            || (i == 25 * 17 && j >= 30 * 20 && j <= 30 * 22)
            || (j == 30 * 8 && i >= 25 * 18 && i <= 25 * 20)
            || (j == 30 * 20 && i >= 25 * 18 && i <= 25 * 20)
            || (i == 25 * 19 && j >= 30 * 5 && j <= 30 * 6)
            || (i == 25 * 20 && j >= 30 * 5 && j <= 30 * 6)
            || (i == 25 * 19 && j >= 30 * 22 && j <= 30 * 23)
            || (i == 25 * 20 && j >= 30 * 22 && j <= 30 * 23)
            || (j == 30 * 10 && i >= 25 * 19 && i <= 25 * 21)
            || (j == 30 * 18 && i >= 25 * 19 && i <= 25 * 21)
            || (i == 25 * 22 && j >= 30 * 6 && j <= 30 * 12)
            || (i == 25 * 22 && j >= 30 * 16 && j <= 30 * 22)
            || (j == 30 * 9 && i >= 25 * 13 && i <= 25 * 15)
            || (j == 30 * 10 && i >= 25 * 13 && i <= 25 * 15)
            || (j == 30 * 18 && i >= 25 * 13 && i <= 25 * 15)
            || (j == 30 * 19 && i >= 25 * 13 && i <= 25 * 15)
            || (j == 30 * 7 && i >= 25 * 13 && i <= 25 * 15)
            || (j == 30 * 21 && i >= 25 * 13 && i <= 25 * 15)
            || (i == 25 * 13 && j >= 30 * 4 && j <= 30 * 6)
            || (i == 25 * 13 && j >= 30 * 22 && j <= 30 * 24)
            || (i == 25 * 11 && j >= 30 * 4 && j <= 30 * 6)
            || (i == 25 * 11 && j >= 30 * 22 && j <= 30 * 24)
            || (j == 30 * 7 && i >= 25 * 9 && i <= 25 * 11)
            || (j == 30 * 21 && i >= 25 * 9 && i <= 25 * 11)
            || (j == 30 * 9 && i >= 25 * 5 && i <= 25 * 11)
            || (j == 30 * 10 && i >= 25 * 5 && i <= 25 * 11)
            || (j == 30 * 18 && i >= 25 * 5 && i <= 25 * 11)
            || (j == 30 * 19 && i >= 25 * 5 && i <= 25 * 11)
            || (j == 30 * 14 && i >= 25 * 7 && i <= 25 * 8)
            || (i == 25 * 6 && j >= 30 * 12 && j <= 30 * 16)
            || (i == 25 * 5 && j >= 30 * 12 && j <= 30 * 16)
            || (j == 30 * 14 && i >= 25 * 1 && i <= 25 * 3)
            || (i == 25 * 8 && j >= 30 * 11 && j <= 30 * 12)
            || (i == 25 * 8 && j >= 30 * 16 && j <= 30 * 17)
            || (i == 25 * 6 && j >= 30 * 6 && j <= 30 * 7)
            || (i == 25 * 5 && j >= 30 * 6 && j <= 30 * 7)
            || (i == 25 * 6 && j >= 30 * 21 && j <= 30 * 22)
            || (i == 25 * 5 && j >= 30 * 21 && j <= 30 * 22)
            || (i == 25 * 2 && j >= 30 * 6 && j <= 30 * 7)
            || (i == 25 * 3 && j >= 30 * 6 && j <= 30 * 7)
            || (i == 25 * 2 && j >= 30 * 21 && j <= 30 * 22)
            || (i == 25 * 3 && j >= 30 * 21 && j <= 30 * 22)
            || (i == 25 * 2 && j >= 30 * 9 && j <= 30 * 12)
            || (i == 25 * 3 && j >= 30 * 9 && j <= 30 * 12)
            || (i == 25 * 2 && j >= 30 * 16 && j <= 30 * 19)
            || (i == 25 * 3 && j >= 30 * 16 && j <= 30 * 19)
            || (i == 25 * 11 && j <= 30 * 4)
            || (i == 25 * 11 && j >= 30 * 25)
            || (i == 25 * 13 && j <= 30 * 4)
            || (i == 25 * 13 && j >= 30 * 25)
            || (i == 25 * 8 && j <= 30 * 7 && j >= 30 * 5)
            || (i == 25 * 8 && j >= 30 * 21 && j <= 30 * 23)
            || (i == 25 * 15 && j <= 30 * 7 && j >= 30 * 5)
            || (i == 25 * 15 && j >= 30 * 21 && j <= 30 * 23)
            || (j == 30 * 4 && (i < 25 * 11 || i >= 25 * 13) && (i <= 25 * 8 || i >= 25 * 11)
            && (i <= 25 * 13 || i >= 25 * 15))
            || (j == 30 * 24 && (i < 25 * 11 || i >= 25 * 13) && (i <= 25 * 8 || i >= 25 * 11)
            && (i <= 25 * 13 || i >= 25 * 15)))
                this->m_map[i][j] = WALL;
            else
                this->m_map[i][j] = EMPTY;
        }
    }
    this->m_difficulty = 0;
    this->m_score = 0;
    this->m_nbPacgum = 0;
    this->m_ghosts.push_back({14 * 30, 11 * 25});
    this->m_ghosts.push_back({13 * 30, 12 * 25});
    this->m_ghosts.push_back({14 * 30, 12 * 25});
    this->m_ghosts.push_back({15 * 30, 12 * 25});
    this->m_ghostIntel.push_back(5);
    this->m_ghostIntel.push_back(4);
    this->m_ghostIntel.push_back(4);
    this->m_ghostIntel.push_back(1);
    for (int i = 0; i < 4; i += 1) {
        this->m_ghostFleeTimer.push_back(std::chrono::system_clock::now());
        this->m_ghostInBase.push_back(true);
        this->m_ghostIsAlive.push_back(true);
        this->m_ghostDir.push_back(DIR_FORWARD);
    }
    this->m_pacman = {14 * 30, 18 * 25};
    this->isAlive = true;
    this->insertPacmanInMap();
    for (int i = 0; i < 25 * 25; i += 1) {
        for (int j = 0; j < 30 * 30; j += 1) {
            if (j > 30 * 4 && j < 30 * 24 && !(i > 8 * 25 && i < 15 * 25 && j > 30 * 4 && j < 30 * 7)
                && !(i > 8 * 25 && i < 15 * 25 && j > 30 * 21 && j < 30 * 24)
                && !(i == 11 * 25 && j == 30 * 13) && !(i == 25 * 11 && j == 30 * 15)
                && j % 30 == 0 && i % 25 == 0 && this->m_map[i][j] == EMPTY
                && !((i == 3 * 25 && (j == 5 * 30 || j == 23 * 30))
                || (i == 18 * 25 && (j == 5 * 30 || j == 23 * 30)))) {
                this->m_map[i + 10][j + 12] = PACGUM;
                this->m_nbPacgum += 1;
            }
            if ((i == 3 * 25 && (j == 5 * 30 || j == 23 * 30))
            || (i == 18 * 25 && (j == 5 * 30 || j == 23 * 30))) {
                this->m_map[i + 3][j + 6] = MEGAPACGUM;
                this->m_nbPacgum += 1;
            }
        }
    }
    this->m_timer = std::chrono::system_clock::now() + std::chrono::microseconds(16000);
    this->m_highscore = this->getHighScore();
    this->m_isStarted = false;
    this->m_speed = 0;
}

int pacman::getHighScore()
{
    std::ifstream highscore("highscore_pacman.txt");
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

void pacman::insertPacmanInMap()
{
    this->m_map[this->m_ghosts[0].y][this->m_ghosts[0].x] = BLINKY;
    this->m_map[this->m_ghosts[1].y][this->m_ghosts[1].x] = PINKY;
    this->m_map[this->m_ghosts[2].y][this->m_ghosts[2].x] = INKY;
    this->m_map[this->m_ghosts[3].y][this->m_ghosts[3].x] = CLYDE;
    for (int i = 0; i < 4; i += 1)
        if (std::chrono::system_clock::now() < this->m_ghostFleeTimer[i])
            this->m_map[this->m_ghosts[i].y][this->m_ghosts[i].x] = FLEEGHOST;
    for (int i = 0; i < 4; i += 1)
        if (!this->m_ghostIsAlive[i])
            this->m_map[this->m_ghosts[i].y][this->m_ghosts[i].x] = DEADGHOST;
    this->m_map[this->m_pacman.y][this->m_pacman.x] = PACMAN;
}

bool pacman::checkWall(int y, int x, DIRECTION dir)
{
    for (int i = 0; i < 30; i += 1) {
        if ((dir == DIR_FORWARD && this->m_map[y - 24][x + i] == WALL)
        || (dir == DIR_FORWARD && this->m_map[y - 24][x + i * -1] == WALL))
            return (true);
        else if ((dir == DIR_BACKWARD && this->m_map[y + 24][x + i] == WALL)
        || (dir == DIR_BACKWARD && this->m_map[y + 24][x + i * -1] == WALL))
            return (true);
    }
    if (dir == DIR_RIGHT && x >= 28 * 30) {
        return (false);
    }
    if (dir == DIR_LEFT && x <= 1 * 30) {
        return (false);
    }
    for (int i = 0; i < 25; i += 1) {
        if ((dir == DIR_RIGHT && this->m_map[y + i][x + 29] == WALL)
        || (dir == DIR_RIGHT && this->m_map[y + i * -1][x + 29] == WALL))
            return (true);
        else if ((dir == DIR_LEFT && this->m_map[y + i][x - 29] == WALL)
        || (dir == DIR_LEFT && this->m_map[y + i * -1][x - 29] == WALL))
            return (true);
    }
    return (false);
}

bool pacman::checkPacman(int y, int x, DIRECTION dir)
{
    if ((y - 24 == this->m_pacman.y
    && x == this->m_pacman.x) || (y + 24 == this->m_pacman.y
    && x == this->m_pacman.x) || (y == this->m_pacman.y
    && x - 29 == this->m_pacman.x) || (y == this->m_pacman.y
    && x + 29 == this->m_pacman.x))
        return (true);
    return (false);
}

bool pacman::checkGhost(int y, int x, DIRECTION dir)
{
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 25; j += 1) {
            if ((y - j == this->m_ghosts[i].y
            && x == this->m_ghosts[i].x) || (y + j == this->m_ghosts[i].y
            && x == this->m_ghosts[i].x)) {
                if (std::chrono::system_clock::now() < this->m_ghostFleeTimer[i]) {
                    this->m_map[this->m_ghosts[i].y][this->m_ghosts[i].x] = EMPTY;
                    this->m_ghostIsAlive[i] = false;
                }
                else if (this->m_ghostIsAlive[i]) {
                    this->isAlive = false;
                    return (true);
                }
            }
        }
        for (int j = 0; j < 30; j += 1) {
            if ((y == this->m_ghosts[i].y
            && x - j == this->m_ghosts[i].x) || (y == this->m_ghosts[i].y
            && x + j == this->m_ghosts[i].x)) {
                if (std::chrono::system_clock::now() < this->m_ghostFleeTimer[i]) {
                    this->m_map[this->m_ghosts[i].y][this->m_ghosts[i].x] = EMPTY;
                    this->m_ghostIsAlive[i] = false;
                }
                else if (this->m_ghostIsAlive[i]) {
                    this->isAlive = false;
                    return (true);
                }
            }
        }
    }
    return (false);
}

void pacman::ghostBeginToFlee()
{
    for (int i = 0; i < this->m_ghosts.size(); i += 1)
        this->m_ghostFleeTimer[i] = std::chrono::system_clock::now() + std::chrono::seconds(7);
}

void pacman::checkPacgum()
{
    if (this->m_dir == DIR_FORWARD && this->m_map[this->m_pacman.y][this->m_pacman.x + 12] == PACGUM) {
        this->m_map[this->m_pacman.y][this->m_pacman.x + 12] = EMPTY;
        this->m_nbPacgum -= 1;
        this->m_score += 100;
    }
    else if (this->m_dir == DIR_BACKWARD && this->m_map[this->m_pacman.y + 24][this->m_pacman.x + 12] == PACGUM) {
        this->m_map[this->m_pacman.y + 24][this->m_pacman.x + 12] = EMPTY;
        this->m_nbPacgum -= 1;
        this->m_score += 100;
    }
    else if (this->m_dir == DIR_RIGHT && this->m_map[this->m_pacman.y + 10][this->m_pacman.x + 29] == PACGUM) {
        this->m_map[this->m_pacman.y + 10][this->m_pacman.x + 29] = EMPTY;
        this->m_nbPacgum -= 1;
        this->m_score += 100;
    }
    else if (this->m_dir == DIR_LEFT && this->m_map[this->m_pacman.y + 10][this->m_pacman.x] == PACGUM) {
        this->m_map[this->m_pacman.y + 10][this->m_pacman.x] = EMPTY;
        this->m_nbPacgum -= 1;
        this->m_score += 100;
    }
    if (this->m_dir == DIR_FORWARD && this->m_map[this->m_pacman.y][this->m_pacman.x + 6] == MEGAPACGUM) {
            this->m_map[this->m_pacman.y][this->m_pacman.x + 6] = EMPTY;
            this->m_nbPacgum -= 1;
            this->m_score += 300;
            this->ghostBeginToFlee();
    }
    else if (this->m_dir == DIR_BACKWARD && this->m_map[this->m_pacman.y + 24][this->m_pacman.x + 6] == MEGAPACGUM) {
            this->m_map[this->m_pacman.y + 24][this->m_pacman.x + 6] = EMPTY;
            this->m_nbPacgum -= 1;
            this->m_score += 300;
            this->ghostBeginToFlee();
    }
    if (this->m_dir == DIR_RIGHT && this->m_map[this->m_pacman.y + 3][this->m_pacman.x + 29] == MEGAPACGUM) {
            this->m_map[this->m_pacman.y + 3][this->m_pacman.x + 29] = EMPTY;
            this->m_nbPacgum -= 1;
            this->m_score += 300;
            this->ghostBeginToFlee();
    }
    else if (this->m_dir == DIR_LEFT && this->m_map[this->m_pacman.y + 3][this->m_pacman.x] == MEGAPACGUM) {
        this->m_map[this->m_pacman.y + 3][this->m_pacman.x] = EMPTY;
        this->m_nbPacgum -= 1;
        this->m_score += 300;
        this->ghostBeginToFlee();
    }
}

void pacman::move(DIRECTION dir, cell &cell)
{
    if (dir == DIR_FORWARD)
        cell.y -= 1;
    else if (dir == DIR_BACKWARD)
        cell.y += 1;
    else if (dir == DIR_RIGHT)
        cell.x += 1;
    else if (dir == DIR_LEFT)
        cell.x -= 1;
}

void pacman::makeDumbMove(int idx, cell &old)
{
    DIRECTION dir[3] = {DIR_LEFT, DIR_RIGHT, DIR_FORWARD};

    if (this->m_ghostDir[idx] == DIR_RIGHT)
        dir[0] = DIR_BACKWARD;
    else if (this->m_ghostDir[idx] == DIR_LEFT)
        dir[1] = DIR_BACKWARD;
    else if (this->m_ghostDir[idx] == DIR_BACKWARD)
        dir[2] = DIR_BACKWARD;
    this->m_ghostDir[idx] = dir[rand() % 4];
    this->move(this->m_ghostDir[idx], this->m_ghosts[idx]);
    while (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
        this->m_ghostDir[idx] = dir[rand() % 4];
        this->m_ghosts[idx].x = old.x;
        this->m_ghosts[idx].y = old.y;
        this->move(this->m_ghostDir[idx], this->m_ghosts[idx]);
    }
}

void pacman::makeGoodMove(int idx, cell &old, cell target)
{
    if (abs(target.x - this->m_ghosts[idx].x) > abs(target.y - this->m_ghosts[idx].y)) {
        if (target.x < this->m_ghosts[idx].x) {
                this->move((this->m_ghostDir[idx] = DIR_LEFT), this->m_ghosts[idx]);
        }
        else
        {
            this->move((this->m_ghostDir[idx] = DIR_RIGHT), this->m_ghosts[idx]);
        }
        if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
            this->m_ghosts[idx].x = old.x;
            this->m_ghosts[idx].y = old.y;
            this->move((this->m_ghostDir[idx] = DIR_BACKWARD), this->m_ghosts[idx]);
            if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
                this->m_ghosts[idx].x = old.x;
                this->m_ghosts[idx].y = old.y;
                this->move((this->m_ghostDir[idx] = DIR_FORWARD), this->m_ghosts[idx]);
            }
        }
    }
    else {
        if (target.y < this->m_ghosts[idx].y) {
                this->move((this->m_ghostDir[idx] = DIR_FORWARD), this->m_ghosts[idx]);
        }
        else
        {
            this->move((this->m_ghostDir[idx] = DIR_BACKWARD), this->m_ghosts[idx]);
        }
        if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
            this->m_ghosts[idx].x = old.x;
            this->m_ghosts[idx].y = old.y;
            this->move((this->m_ghostDir[idx] = DIR_RIGHT), this->m_ghosts[idx]);
            if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
                this->m_ghosts[idx].x = old.x;
                this->m_ghosts[idx].y = old.y;
                this->move((this->m_ghostDir[idx] = DIR_LEFT), this->m_ghosts[idx]);
            }
        }
    }
}

void pacman::goToBase(int idx)
{
    for (int i = 0; i < 7; i += 1) {
        cell old = {this->m_ghosts[idx].x, this->m_ghosts[idx].y};
        int count = 0;
        DIRECTION dir[4] = {DIR_LEFT, DIR_RIGHT, DIR_FORWARD, DIR_BACKWARD};

        for (int j = 0; j < 4; j += 1) {
            this->m_ghosts[idx].x = old.x;
            this->m_ghosts[idx].y = old.y;
            this->move(dir[j], this->m_ghosts[idx]);
            if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, dir[j]) || this->m_ghostDir[idx] == dir[j])
                count++;
        }
        this->m_ghosts[idx].x = old.x;
        this->m_ghosts[idx].y = old.y;
        if (count <= 2) {
            int random = rand() % 2 + 1;
            if (random != 1)
                this->makeGoodMove(idx, old, {14 * 30, 9 * 25});
            else
                this->makeDumbMove(idx, old);
        }
        else
            this->move(this->m_ghostDir[idx], this->m_ghosts[idx]);
        this->m_map[old.y][old.x] = EMPTY;
        if (this->m_ghosts[idx].x == 14 * 30 && this->m_ghosts[idx].y == 9 * 25) {
            this->m_ghostIsAlive[idx] = true;
            this->m_ghostInBase[idx] = true;
            this->m_ghosts[idx] = {14 * 30, 11 * 25};
            this->m_ghostTimer[idx] = std::chrono::system_clock::now() + std::chrono::seconds(2);
            this->m_ghostFleeTimer[idx] = std::chrono::system_clock::now();
        }
    }
}

void pacman::chasePacman(int idx)
{
    for (int i = 0; i < 4 + this->m_difficulty + this->m_speed; i += 1) {
        cell old = {this->m_ghosts[idx].x, this->m_ghosts[idx].y};
        int count = 0;
        DIRECTION dir[4] = {DIR_LEFT, DIR_RIGHT, DIR_FORWARD, DIR_BACKWARD};

        for (int j = 0; j < 4; j += 1) {
            this->m_ghosts[idx].x = old.x;
            this->m_ghosts[idx].y = old.y;
            this->move(dir[j], this->m_ghosts[idx]);
            if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, dir[j]) || this->m_ghostDir[idx] == dir[j])
                count++;
        }
        this->m_ghosts[idx].x = old.x;
        this->m_ghosts[idx].y = old.y;
        if (count <= 2) {
            int random = rand() % this->m_ghostIntel[idx] + 1;
            if (random != 1 && random != 2 && random != 3)
                this->makeGoodMove(idx, old, this->m_pacman);
            else
                this->makeDumbMove(idx, old);
        }
        else
            this->move(this->m_ghostDir[idx], this->m_ghosts[idx]);
        this->m_map[old.y][old.x] = EMPTY;
        if (this->checkPacman(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
            this->isAlive = false;
            return;
        }
    }
}

void pacman::goOutBase(int idx)
{
    this->m_map[this->m_ghosts[idx].y][this->m_ghosts[idx].x] = EMPTY;
    this->m_ghosts[idx].x = 14 * 30;
    this->m_ghosts[idx].y = 9 * 25;
    this->m_ghostInBase[idx] = false;
    if (this->checkPacman(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
        this->isAlive = false;
    }
}

void pacman::flee(int idx)
{
    for (int i = 0; i < 2; i += 1) {
        cell old = {this->m_ghosts[idx].x, this->m_ghosts[idx].y};
        int count = 0;
        DIRECTION dir[4] = {DIR_LEFT, DIR_RIGHT, DIR_FORWARD, DIR_BACKWARD};

        for (int j = 0; j < 4; j += 1) {
            this->m_ghosts[idx].x = old.x;
            this->m_ghosts[idx].y = old.y;
            this->move(dir[j], this->m_ghosts[idx]);
            if (this->checkWall(this->m_ghosts[idx].y, this->m_ghosts[idx].x, dir[j]) || this->m_ghostDir[idx] == dir[j])
                count++;
        }
        this->m_ghosts[idx].x = old.x;
        this->m_ghosts[idx].y = old.y;
        if (count <= 2)
                this->makeDumbMove(idx, old);
        else
            this->move(this->m_ghostDir[idx], this->m_ghosts[idx]);
        this->m_map[old.y][old.x] = EMPTY;
        if (this->checkPacman(this->m_ghosts[idx].y, this->m_ghosts[idx].x, this->m_ghostDir[idx])) {
            this->m_map[this->m_ghosts[idx].y][this->m_ghosts[idx].x] = EMPTY;
            this->m_ghostIsAlive[idx] = false;
            this->m_ghostFleeTimer[idx] = std::chrono::system_clock::now();
            return;
        }
    }
}

void pacman::moveAutoGhosts()
{
    for (int i = 0; i < 4; i += 1) {
        if (this->m_ghostInBase[i] && std::chrono::system_clock::now() > this->m_ghostTimer[i]) {
            this->goOutBase(i);
        }
        else if (!this->m_ghostIsAlive[i]) {
            this->goToBase(i);
        }
        else if (!this->m_ghostInBase[i] && std::chrono::system_clock::now() >= this->m_ghostFleeTimer[i])
            this->chasePacman(i);
        else if (!this->m_ghostInBase[i] && std::chrono::system_clock::now() < this->m_ghostFleeTimer[i]) {
            this->flee(i);
        }
        if (this->m_ghosts[i].x <= 0) {
            this->m_ghosts[i].x = 29 * 30;
            this->m_ghosts[i].y = 12 * 25;
        }
        else if (this->m_ghosts[i].x >= 29 * 30) {
            this->m_ghosts[i].x = 0 * 30;
            this->m_ghosts[i].y = 12 * 25;
        }
    }
}

void pacman::moveAutoPacman(DIRECTION &oldDir, DIRECTION &tmp)
{
    for (int i = 0; i < 5 + this->m_speed; i += 1) {
        cell old = {this->m_pacman.x, this->m_pacman.y};

        this->m_dir = tmp;
        this->m_map[this->m_pacman.y][this->m_pacman.x] = EMPTY;
        this->move(this->m_dir, this->m_pacman);
        if (this->checkWall(this->m_pacman.y, this->m_pacman.x, this->m_dir)) {
            this->m_pacman.x = old.x;
            this->m_pacman.y = old.y;
            this->m_dir = oldDir;
            this->move(this->m_dir, this->m_pacman);
            if (this->checkWall(this->m_pacman.y, this->m_pacman.x, this->m_dir)) {
                this->m_pacman.x = old.x;
                this->m_pacman.y = old.y;
            }
        }
        if (this->m_pacman.x <= 0) {
            this->m_pacman.x = 29 * 30;
            this->m_pacman.y = 12 * 25;
        }
        else if (this->m_pacman.x >= 29 * 30) {
            this->m_pacman.x = 0 * 30;
            this->m_pacman.y = 12 * 25;
        }
        oldDir = this->m_dir;
        this->checkPacgum();
        if (this->checkGhost(this->m_pacman.y, this->m_pacman.x, this->m_dir))
            return;
    }
}

void pacman::restartPacman(bool incDif)
{
    if (incDif)
        this->m_difficulty += 1;
    else {
        std::ofstream highscore;
        highscore.open ("highscore_pacman.txt", std::ios_base::app);
        highscore << m_score << std::endl << m_name << std::endl;
        highscore.close();
        this->m_score = 0;
        this->m_highscore = this->getHighScore();
    }
    this->m_nbPacgum = 0;
    this->m_map[this->m_pacman.y][this->m_pacman.x] = EMPTY;
    for (int i = 0; i < 4; i += 1) {
        this->m_map[this->m_ghosts[i].y][this->m_ghosts[i].x ]= EMPTY;
        this->m_ghostFleeTimer[i] = (std::chrono::system_clock::now());
        this->m_ghostTimer[i] = (std::chrono::system_clock::now() + std::chrono::seconds(10 + i * 2));
        this->m_ghostInBase[i] = (true);
        this->m_ghostIsAlive[i] = (true);
        this->m_ghostDir[i] = (DIR_FORWARD);
    }
    this->m_ghosts[0] = {14 * 30, 11 * 25};
    this->m_ghosts[1] = {13 * 30, 12 * 25};
    this->m_ghosts[2] = {14 * 30, 12 * 25};
    this->m_ghosts[3] = {15 * 30, 12 * 25};
    this->m_pacman = {14 * 30, 18 * 25};
    this->isAlive = true;
    this->insertPacmanInMap();
    for (int i = 0; i < 25 * 25; i += 1) {
        for (int j = 0; j < 30 * 30; j += 1) {
            if (j > 30 * 4 && j < 30 * 24 && !(i > 8 * 25 && i < 15 * 25 && j > 30 * 4 && j < 30 * 7)
                && !(i > 8 * 25 && i < 15 * 25 && j > 30 * 21 && j < 30 * 24)
                && !(i == 11 * 25 && j == 30 * 13) && !(i == 25 * 11 && j == 30 * 15)
                && j % 30 == 0 && i % 25 == 0 && this->m_map[i][j] == EMPTY
                && !((i == 3 * 25 && (j == 5 * 30 || j == 23 * 30))
                || (i == 18 * 25 && (j == 5 * 30 || j == 23 * 30)))) {
                this->m_map[i + 10][j + 12] = PACGUM;
                this->m_nbPacgum += 1;
            }
            if ((i == 3 * 25 && (j == 5 * 30 || j == 23 * 30))
            || (i == 18 * 25 && (j == 5 * 30 || j == 23 * 30))) {
                this->m_map[i + 3][j + 6] = MEGAPACGUM;
                this->m_nbPacgum += 1;
            }
        }
    }
    this->m_timer = std::chrono::system_clock::now() + std::chrono::microseconds(16000);
    this->m_dir = DIRECTION::DIR_FORWARD;
    this->m_tmp = DIRECTION::DIR_FORWARD;
    this->m_speedTimer = std::chrono::system_clock::now() + std::chrono::seconds(30);
    this->m_speed = 0;
}

EVENTS pacman::start()
{
    if (!this->m_isStarted) {
        for (int i = 0; i < 4; i += 1)
            this->m_ghostTimer.push_back(std::chrono::system_clock::now() + std::chrono::seconds(10 + i * 2));
        this->m_isStarted = true;
        this->m_speedTimer = std::chrono::system_clock::now() + std::chrono::seconds(30);
    }
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
            this->restartPacman(false);
        if (std::chrono::system_clock::now() > this->m_speedTimer) {
            this->m_speed += 1;
            this->m_speedTimer = std::chrono::system_clock::now() + std::chrono::seconds(30);
        }
        if (std::chrono::system_clock::now() > this->m_timer) {
            this->m_oldDir = this->m_dir;
            this->m_dir = this->m_tmp;
            this->moveAutoGhosts();
            if (this->isAlive)
                this->moveAutoPacman(this->m_oldDir, this->m_tmp);
            if (!this->isAlive)
                this->restartPacman(false);
            if (this->m_nbPacgum == 0)
                this->restartPacman(true);
            this->insertPacmanInMap();
            this->m_timer = std::chrono::system_clock::now() + std::chrono::microseconds(16000);
        }
        this->m_display->drawMap(this->m_map);
        this->m_display->drawScore(this->m_score, m_highscore);
        this->m_display->display();
    }
    if (this->m_evt == EVENTS::EXIT
    || this->m_evt == EVENTS::NEXTLIB || this->m_evt == EVENTS::PREVLIB)
        this->m_display->closeWindow();
    if (this->m_evt == EVENTS::EXIT) {
        std::ofstream highscore;
        highscore.open ("highscore_pacman.txt", std::ios_base::app);
        highscore << m_score << std::endl << m_name << std::endl;
        highscore.close();
    }
    return (this->m_evt);
}