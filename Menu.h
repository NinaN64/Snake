#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu {
    sf::Text text;
    sf::Font font;
public:
    Menu();
    int MenuStart(sf::RenderWindow & win);

};


#endif //SNAKE_MENU_H
