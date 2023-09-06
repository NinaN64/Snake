#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Snake.h"




int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);
    Menu menu;
    Snake snake;


    //snake.gameStart();

    while (window.isOpen())
    {
        sf::Event event;




        window.clear();

        if (snake.getGState() == MENU) {
            snake.GetGameMode(window);
        }
        if (snake.getGState() == GAMEPLAY) {
            snake.draw(window);

            snake.Gameplay();
        }
        while (window.pollEvent(event)) {


            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (snake.getGState() == MENU) {
                snake.PickGMode(event);
            }
            //std::cout << "Pressed button: " << event.key.code << "\n";
            //std::cout << snake.getDIr();
            if (snake.getGState() == GAMEPLAY) {
            snake.PlayerMove(window, event);
            }
        }



            if (snake.getGState() == GAMEOVER) {
                snake.GameOverdisp(window);
            }



        //menu.MenuStart(window);
        //snake.Gameplay();

        window.display();



    }

    return 0;
}