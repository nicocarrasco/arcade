/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sfml
*/

#include "sfml.hpp"

sfml::sfml()
{
    this->m_window = new sf::RenderWindow(sf::VideoMode(900, 625), "Arcade");
    this->m_window->setFramerateLimit(60);
    m_wall = new sf::RectangleShape(sf::Vector2f(30, 25));
    m_wall->setFillColor(sf::Color::Blue);
    s_character = new sf::Sprite;
    t_character = new sf::Texture;
    t_clyde = new sf::Texture;
    s_clyde = new sf::Sprite;
    t_fruit = new sf::Texture;
    s_fruit = new sf::Sprite;
    t_snake = new sf::Texture;
    s_snake = new sf::Sprite;
    t_hsnake = new sf::Texture;
    s_hsnake = new sf::Sprite;
    s_blinky = new sf::Sprite;
    t_blinky = new sf::Texture;
    s_pinky = new sf::Sprite;
    t_pinky = new sf::Texture;
    s_inky = new sf::Sprite;
    t_inky = new sf::Texture;
    s_fleeGhost = new sf::Sprite;
    t_fleeGhost = new sf::Texture;
    m_pacgum = new sf::CircleShape(3.0f);
    m_pacgum->setFillColor(sf::Color::Yellow);
    t_megapacgum = new sf::Texture;
    s_megapacgum = new sf::Sprite;
    s_eyeGhost = new sf::Sprite;
    t_eyeGhost = new sf::Texture;
    _clock = new sf::Clock;

    m_Game[0] = new sf::Text;
    m_Game[1] = new sf::Text;
    font = new sf::Font;
    if (!font->loadFromFile("lib/sfml/Asset/Font/arial.ttf")) {
        exit (84);
    }
    _rect_ch = new sf::IntRect(0, 0, 22.5, 24);
    _rect_Ghost = new sf::IntRect(0, 0, 25, 25);
    if ((!this->t_character->loadFromFile("lib/sfml/Asset/Pacman/Right.png")) ||
    (!this->t_megapacgum->loadFromFile("lib/sfml/Asset/Pacman/MegaPacgum.png")) ||
    (!this->t_clyde->loadFromFile("lib/sfml/Asset/Pacman/Clyde.png")) ||
    (!this->t_blinky->loadFromFile("lib/sfml/Asset/Pacman/Blinky.png")) ||
    (!this->t_pinky->loadFromFile("lib/sfml/Asset/Pacman/Inky.png")) ||
    (!this->t_inky->loadFromFile("lib/sfml/Asset/Pacman/Pinky.png")) ||
    (!this->t_fleeGhost->loadFromFile("lib/sfml/Asset/Pacman/FleeGhost.png")) ||
    (!this->t_eyeGhost->loadFromFile("lib/sfml/Asset/Pacman/Eye_Ghost.png")) ||
    (!this->t_fruit->loadFromFile("lib/sfml/Asset/Nibbler/Item/Apple.png")) ||
    (!this->t_snake->loadFromFile("lib/sfml/Asset/Nibbler/Body/Body_V.png")) ||
    (!this->t_hsnake->loadFromFile("lib/sfml/Asset/Nibbler/Head/Head_down.png")))
        exit(84);
    this->s_character->setTexture(*this->t_character);
    this->s_character->setTextureRect(*this->_rect_ch);
    this->s_clyde->setTexture(*this->t_clyde);
    this->s_blinky->setTexture(*this->t_blinky);
    this->s_pinky->setTexture(*this->t_pinky);
    this->s_inky->setTexture(*this->t_inky);
    this->s_fleeGhost->setTexture(*this->t_fleeGhost);
    this->s_megapacgum->setTexture(*this->t_megapacgum);
    this->s_eyeGhost->setTexture(*this->t_eyeGhost);
    this->s_fruit->setTexture(*this->t_fruit);
    this->s_snake->setTexture(*this->t_snake);
    this->s_hsnake->setTexture(*this->t_hsnake);
    m_Game[0]->setFont(*font);
    m_Game[0]->setFillColor(sf::Color::Red);
    m_Game[0]->setPosition(sf::Vector2f((900 / 2) / 2, 625 / (2 + 1) * 1));
    m_Game[1]->setFont(*font);
    m_Game[1]->setFillColor(sf::Color::White);
    m_Game[1]->setPosition(sf::Vector2f((900 / 2) / 2, 625 / (2 + 1) * 2));
}

sfml::~sfml()
{

}

void sfml::init()
{
    return;
}

void sfml::display() const
{
    this->m_window->display();
}

EVENTS sfml::getEvent() const
{
    sf::Event evt;

    while (this->m_window->pollEvent(evt)) {
        if ((evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::Escape ) ||
        (evt.type == sf::Event::Closed))
            return (EVENTS::EXIT);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if ((!this->t_character->loadFromFile("lib/sfml/Asset/Pacman/Up.png")) ||
            (!this->t_snake->loadFromFile("lib/sfml/Asset/Nibbler/Body/Body_V.png")) ||
            (!this->t_hsnake->loadFromFile("lib/sfml/Asset/Nibbler/Head/Head_up.png")))
                exit(84);
            this->s_snake->setTexture(*this->t_snake);
            this->s_hsnake->setTexture(*this->t_hsnake);
            this->s_character->setTexture(*this->t_character);
            *_rect_ch = sf::IntRect(0, 0, 24, 22.5);
            this->s_character->setTextureRect(*this->_rect_ch);
            return (EVENTS::UP);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if ((!this->t_character->loadFromFile("lib/sfml/Asset/Pacman/Down.png")) ||
            (!this->t_snake->loadFromFile("lib/sfml/Asset/Nibbler/Body/Body_V.png")) ||
            (!this->t_hsnake->loadFromFile("lib/sfml/Asset/Nibbler/Head/Head_down.png")))
                exit(84);
            this->s_snake->setTexture(*this->t_snake);
            this->s_hsnake->setTexture(*this->t_hsnake);
            this->s_character->setTexture(*this->t_character);
            *_rect_ch =  sf::IntRect(0, 0, 25, 25);
            this->s_character->setTextureRect(*this->_rect_ch);
            return (EVENTS::DOWN);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if ((!this->t_character->loadFromFile("lib/sfml/Asset/Pacman/Left.png")) ||
            (!this->t_snake->loadFromFile("lib/sfml/Asset/Nibbler/Body/Body_H.png")) ||
            (!this->t_hsnake->loadFromFile("lib/sfml/Asset/Nibbler/Head/Head_left.png")))
                exit(84);
            this->s_snake->setTexture(*this->t_snake);
            this->s_hsnake->setTexture(*this->t_hsnake);
            this->s_character->setTexture(*this->t_character);
            *_rect_ch = sf::IntRect(0, 0, 25, 25);
            this->s_character->setTextureRect(*this->_rect_ch);
            return (EVENTS::LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if ((!this->t_character->loadFromFile("lib/sfml/Asset/Pacman/Right.png")) ||
            (!this->t_snake->loadFromFile("lib/sfml/Asset/Nibbler/Body/Body_H.png")) ||
            (!this->t_hsnake->loadFromFile("lib/sfml/Asset/Nibbler/Head/Head_right.png")))
                exit(84);
            this->s_snake->setTexture(*this->t_snake);
            this->s_hsnake->setTexture(*this->t_hsnake);
            this->s_character->setTexture(*this->t_character);
            *_rect_ch = sf::IntRect(0, 0, 22.5, 24);
            this->s_character->setTextureRect(*this->_rect_ch);
            return (EVENTS::RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
            return (EVENTS::NEXTLIB);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            return (EVENTS::PREVLIB);
        else if (evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::A)
            return (EVENTS::PREVGAME);
        else if (evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::Z)
            return (EVENTS::NEXTGAME);
        else if (evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::M)
            return (EVENTS::MENU);
        else if (evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::R)
            return (EVENTS::RESTART);
        else
            break;
    }
    return (EVENTS::UNKNOWN);
}

int sfml::menu(std::map<int, std::string> list) const
{
    sf::Event evt;
    int choice = 0;
    int menu = 1;
    m_Game[0]->setString("Nibbler");
    m_Game[1]->setString("Pacman");
    m_Game[0]->setFillColor(sf::Color::Red);
    m_Game[1]->setFillColor(sf::Color::White);

    while (menu == 1) {
        while (m_window->pollEvent(evt)) {
            if (evt.type == sf::Event::KeyReleased && evt.key.code == sf::Keyboard::Return) {
                menu = 0;
                break;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (choice - 1 >= 0) {
                    m_Game[choice]->setFillColor(sf::Color::White);
                    choice -= 1;
                    m_Game[choice]->setFillColor(sf::Color::Red);
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (choice + 1 < 2) {
                    m_Game[choice]->setFillColor(sf::Color::White);
                        choice += 1;
                    m_Game[choice]->setFillColor(sf::Color::Red);
                }
            }
        }
        m_window->clear();
        for (int i = 0; i < 2; i += 1) {
            m_window->draw(*m_Game[i]);
        }
        display();
    }
    return (choice);
}

void sfml::drawMap(MAPTYPE **map) const
{
    this->m_window->clear();
    if (_clock->getElapsedTime().asSeconds() > 0.10f) {
        (_rect_Ghost->top >= 25) ? this->_rect_Ghost->top = 0 : 0;
        if (this->_rect_ch->top >= 50) {
            this->_rect_ch->top = 0;
        } else {
            this->_rect_ch->top += 26;
            this->_rect_Ghost->top += 26;
        }
        this->s_character->setTextureRect(*_rect_ch);
        this->s_clyde->setTextureRect(*_rect_Ghost);
        _clock->restart();
    }
    for (int i = 0; i < 625; i += 1) {
        for (int j = 0; j < 900; j += 1) {
            if (map[i][j] == MEGAPACGUM) {
                this->s_megapacgum->setPosition(j, i);
                this->m_window->draw(*this->s_megapacgum);
            } else if (map[i][j] == PACGUM) {
                this->m_pacgum->setPosition(j, i);
                this->m_window->draw(*this->m_pacgum);
            }
        }
    }
    for (int i = 0; i < 625; i += 1) {
        for (int j = 0; j < 900; j += 1) {
            if (map[i][j] == WALL) {
                this->m_wall->setPosition(j, i);
                this->m_window->draw(*this->m_wall);
            }
            else if (map[i][j] == SNAKE_HEAD) {
                this->s_hsnake->setPosition(j, i);
                this->m_window->draw(*this->s_hsnake);
            }
            else if (map[i][j] == SNAKE) {
                this->s_snake->setPosition(j, i);
                this->m_window->draw(*this->s_snake);
            }
            else if (map[i][j] == PACMAN) {
                this->s_character->setPosition(j, i);
                this->m_window->draw(*this->s_character);
            }
            else if (map[i][j] == ITEM) {
                this->s_fruit->setPosition(j, i);
                this->m_window->draw(*this->s_fruit);
            }
            else if (map[i][j] == BLINKY) {
                this->s_blinky->setTextureRect(*this->_rect_Ghost);
                this->s_blinky->setPosition(j, i);
                this->m_window->draw(*this->s_blinky);
            }
            else if (map[i][j] == PINKY) {
                this->s_pinky->setTextureRect(*this->_rect_Ghost);
                this->s_pinky->setPosition(j, i);
                this->m_window->draw(*this->s_pinky);
            }
            else if (map[i][j] == INKY) {
                this->s_inky->setTextureRect(*this->_rect_Ghost);
                this->s_inky->setPosition(j, i);
                this->m_window->draw(*this->s_inky);
            }
            else if (map[i][j] == CLYDE) {
                this->s_clyde->setTextureRect(*this->_rect_Ghost);
                this->s_clyde->setPosition(j, i);
                this->m_window->draw(*this->s_clyde);
            }
            else if (map[i][j] == FLEEGHOST) {
                this->s_fleeGhost->setTextureRect(*this->_rect_Ghost);
                this->s_fleeGhost->setPosition(j, i);
                this->m_window->draw(*this->s_fleeGhost);
            }
            else if (map[i][j] == DEADGHOST) {
                this->s_eyeGhost->setPosition(j, i);
                this->m_window->draw(*this->s_eyeGhost);
            }
        }
    }
}

void sfml::drawScore(int score, int highscore) const
{
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    std::string s_score(std::to_string(score));
    std::string s_highscore(std::to_string(highscore));

    if (!font.loadFromFile("lib/sfml/Asset/Font/arial.ttf")) {
        exit(84);
    }
    text.setFont(font);
    text.setString("Score : " + s_score);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    this->m_window->draw(text);
    text2.setFont(font);
    text2.setString("High Score : " + s_highscore);
    text2.setCharacterSize(18);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(0, 30);
    this->m_window->draw(text2);
}

void sfml::closeWindow()
{
    this->m_window->close();
}