#include "Snake.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "windows.h"

Snake::Snake()
{
    GState = MENU;
    SnakeDirection = STOP;
    GMode = HARD;
    SnakePosX = 10;
    SnakePosY = 10;
    Tails = 0;
    score = 0;
    apple.NewApple(BoardHeight, BoardWidth);
}


void Snake::HeadDirection( MoveDirection direction) {
    if((direction == LEFT && SnakeDirection == RIGHT) || (direction == RIGHT && SnakeDirection == LEFT)) return;

    if ((direction == UP && SnakeDirection == DOWN) || (direction == DOWN && SnakeDirection == UP)) return;

    SnakeDirection = direction;
}
void Snake::PlayerMove( sf::RenderWindow & win, sf::Event & event) {
    MoveDirection help;

    //if (_kbhit())
    //{
        if(GMode == EASY) Sleep(100);
        if(GMode == NORMAL) Sleep(50);
        if(GMode == HARD) Sleep(10);
                    std::cout << "Pressed button: " << event.key.code << "\n";
                    if(event.key.code == sf::Keyboard::Up)
                    {
                        help = UP;
                        HeadDirection(help);
                        std::cout<<"Jestem";
                    }
                    if(event.key.code == sf::Keyboard::Down)
                    {
                        help = DOWN;
                        HeadDirection(help);
                        std::cout<<"Jestem";
                    }
            if(event.key.code == sf::Keyboard::Right)
            {
                help = RIGHT;
                HeadDirection(help);
                std::cout<<"Jestem";
            }
            if(event.key.code == sf::Keyboard::Left)
            {
                help = LEFT;
                HeadDirection(help);
                std::cout<<"Jestem";
            }
    }
//}



GameState Snake::getGState() {
    return GState;
}

void Snake::Gameplay() {
    int previousX = SnakeTailX[0];
    int previousY = SnakeTailY[0];
    int HelpX, HelpY;
    SnakeTailX[0] = SnakePosX;
    SnakeTailY[0] = SnakePosY;

    for(int i=1; i<Tails; i++)
    {
        HelpX = SnakeTailX[i];
        HelpY = SnakeTailY[i];
        SnakeTailX[i] = previousX;
        SnakeTailY[i] = previousY;
        previousX = HelpX;
        previousY = HelpY;
    }

    switch(SnakeDirection)
    {
        case LEFT:
            SnakePosX--;
            break;
        case RIGHT:
            SnakePosX++;
            break;
        case UP:
            SnakePosY--;
            break;
        case DOWN:
            SnakePosY++;
            break;
        default:
            break;
    }
    CollisionWall(SnakePosX, SnakePosY);
    for(int i = 0; i<Tails; i++) {
        CollisionSnake(SnakeTailX[i], SnakeTailY[i]);
    }
    if(SnakePosX == apple.getAppleX() && SnakePosY == apple.getAppleY())
    {
        if(GMode == EASY)
        {
            score += 3;
            apple.NewApple(BoardHeight-1, BoardWidth-1);
            Tails += 3;

        }
        if(GMode == NORMAL)
        {
            score += 2;
            apple.NewApple(BoardHeight-1, BoardWidth-1);
            Tails += 2;

        }
        if(GMode == HARD) {
            score++;
            apple.NewApple(BoardHeight-1, BoardWidth-1);
            Tails++;
        }
    }

}

void Snake::CollisionSnake(int x, int y)
{
    if(x == SnakePosX && y == SnakePosY)
    {
        GState = GAMEOVER;
    }
    return;
}

void Snake::CollisionWall(int x, int y)
{
    if(x >= BoardWidth || x < 0) GState = GAMEOVER;
    if(y >= BoardHeight || y < 0) GState = GAMEOVER;
    return;
}

void Snake::draw(sf::RenderWindow & win)
{
    system ("cls");

        WallGraf.setFillColor(sf::Color::Magenta);
        WallGraf.setSize(sf::Vector2f(SquareSize, SquareSize));

        TailGraf.setFillColor(sf::Color::Green);
        TailGraf.setSize(sf::Vector2f(SquareSize, SquareSize));

        AppleGraf.setFillColor(sf::Color::Red);
        AppleGraf.setSize(sf::Vector2f(SquareSize, SquareSize));
        for(int x = 0; x<BoardWidth; x++)
        {
            WallGraf.setPosition(x*SquareSize, 0);
            win.draw(WallGraf);
        }
       for(int y = 0; y<BoardHeight; y++)
       {
           for(int x = 0; x<BoardWidth; x++)
           {
               int posX = SquareSize * x;
               int posY = SquareSize * y;

               if(x == 0) //sciana
               {

                   WallGraf.setPosition(posX, posY);
                   win.draw(WallGraf);
               }
               if(y == SnakePosY && x == SnakePosX) //jablko
               {
                   TailGraf.setPosition(posX,posY);
                   win.draw(TailGraf);
               }
               if(y == apple.getAppleY() && x == apple.getAppleX()) //snake glowa
               {
                   AppleGraf.setPosition(posX, posY);
                   win.draw(AppleGraf);
               }
                else
               {
                    for(int a=0; a<Tails; a++) //ogony
                    {
                        if(SnakeTailX[a] == x && SnakeTailY[a] == y)
                        {
                            TailGraf.setPosition(posX, posY);
                            win.draw(TailGraf);
                        }
                    }
               }
                if(x == BoardWidth-1) //sciana
                {
                    WallGraf.setPosition(posX, posY);
                    win.draw(WallGraf);
                }


           }
       }
       for(int x = 0; x<BoardWidth+2; x++)
       {
           WallGraf.setPosition(x*SquareSize, (BoardHeight-1)*SquareSize);
           win.draw(WallGraf);
       }
    }

void Snake::GetGameMode(sf::RenderWindow & win) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C://SFML-2.5.1//Textures//Helvetica.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Green);
    text.setPosition(250, 0);
    text.setCharacterSize(100);
    text.setString("Snake");
    win.draw(text);
    text.setString("1.EASY");
    text.setPosition(270, 200);
    text.setCharacterSize(50);
    win.draw(text);
    text.setString("2.NORMAL");
    text.setPosition(270, 300);
    text.setCharacterSize(50);
    win.draw(text);
    text.setString("3.HARD");
    text.setPosition(270, 400);
    text.setCharacterSize(50);
    win.draw(text);


}

void Snake::GameOverdisp(sf::RenderWindow & win) const
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C://SFML-2.5.1//Textures//Helvetica.ttf");
    text.setFont(font);
    text.setPosition(250, 0);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    std::ofstream file;
    text.setString("Scores:");
    win.draw(text);
    text.setCharacterSize(20);


    file.open("C://SFML-2.5.1/Scores.txt", std::ios_base::app);
    if(file.is_open())
    {
        file<<std::endl<<score;
        //std::cout<<"Sukces";
        file.close();
    }
    else std::cout<<"Problem";

    std::ifstream file1 ("C://SFML-2.5.1/Scores.txt");
    if(file1.is_open())
    {
        int q = 70;
        std::string a;
        for(int i=0; i<10; i++)
        {
            getline(file1, a);

            text.setPosition(250, q);
            text.setString(a);
            win.draw(text);
            q+=50;


        }
        file.close();

    }
}

MoveDirection Snake::getDIr() {
    return SnakeDirection;
}

void Snake::PickGMode(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            GMode = EASY;
        }
        if (event.key.code == sf::Keyboard::Num2) {
            GMode = NORMAL;
        }
        if (event.key.code == sf::Keyboard::Num3) {
            GMode = HARD;
        }

        GState = GAMEPLAY;
    }
}