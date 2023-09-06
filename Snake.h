#pragma once
#include "Apple.h"
#include <conio.h>
#include "Menu.h"
#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>




enum GameState {MENU, GAMEPLAY, GAMEOVER};
enum MoveDirection {STOP, LEFT, RIGHT, UP, DOWN};
enum GameMode {EASY, NORMAL, HARD};
//int SquareSize = 20;

class Snake {
    int snakeSize;
    MoveDirection SnakeDirection;
    sf::RectangleShape TailGraf;
    sf::RectangleShape WallGraf;
    sf::RectangleShape AppleGraf;
    //sf::RectangleShape BlackSpot;
    int SnakePosX; //position x of Snake
    int SnakePosY; //position y of Snake
    int Tails; //how many tails
    GameState GState;
    int BoardHeight = 30;
    int BoardWidth = 40;
    int SquareSize = 20;
    int SnakeTailX[100]; //wspolzedne x
    int SnakeTailY[100];//wspolzedne y
    Apple apple;
    int score;
    GameMode GMode;
    Menu menu;

public:
    Snake();
    void draw(sf::RenderWindow & win);
    GameState getGState();

    //void gameStart();
    void HeadDirection( MoveDirection direction); //sprawdza czy moze isc w dana strone
    void PlayerMove(sf::RenderWindow & win, sf::Event & event);
    void Gameplay();
    MoveDirection getDIr();
    void PickGMode( sf::Event& event);
    void CollisionSnake(int x, int y);
    void CollisionWall(int x, int y);
    void GetGameMode(sf::RenderWindow & win);
    void GameOverdisp(sf::RenderWindow & win) const;
};



#endif //SNAKE_H
