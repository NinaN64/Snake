#include "Menu.h"

Menu::Menu()
{

}

int Menu::MenuStart(sf::RenderWindow & win)
{
    font.loadFromFile("C://SFML-2.5.1//Textures//Helvetica.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Green);
    text.setPosition(250,0);
    text.setCharacterSize(100);
    text.setString("Snake");
    win.draw(text);
    text.setString("1.EASY");
    text.setPosition(270,200);
    text.setCharacterSize(50);
    win.draw(text);
    text.setString("2.NORMAL");
    text.setPosition(270,300);
    text.setCharacterSize(50);
    win.draw(text);
    text.setString("3.HARD");
    text.setPosition(270,400);
    text.setCharacterSize(50);
    win.draw(text);


}




