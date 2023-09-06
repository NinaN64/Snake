#include "Apple.h"
#include <stdlib.h>


Apple::Apple()
{
    AppleSize = 10;
    //Food.setSize(sf::Vector2f(AppleSize,AppleSize));
    //Food.setFillColor(sf::Color::Red);

}

void Apple::NewApple(int h, int w)
{
    AppleX = rand() % w;
    AppleY = rand() % h;
    return;
}


int Apple::getAppleX() {
    return AppleX;
}

int Apple::getAppleY()
{
    return AppleY;
}


