// sfmltest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h" 

int main()
{
    Game g(1080, 720, "Battle", "./Resources/chuttiya.png");
    g.run();
    return 0;
}