
#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H
#include <stdlib.h>


class Apple {
    int AppleX;
    int AppleY;
    int AppleSize;
public:
    Apple();
    void NewApple(int h, int w);
    int getAppleX();
    int getAppleY();
};


#endif //SNAKE_APPLE_H
