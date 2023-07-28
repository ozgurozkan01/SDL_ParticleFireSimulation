#include <SDL.h>
#include <iostream>
#include "Screen.h"

int main(int argc, char *argv[])
{

    Screen screen;

    if (!screen.init())
    {
        std::cout << "Error initialising SDL!!" << std::endl;
        return -1;
    }

    int i = 0;
    int j = 255;
    while(true)
    {

        for (int yCord = 0; yCord < Screen::SCREEN_HEIGHT; ++yCord)
        {
            for (int xCord = 0; xCord < Screen::SCREEN_WIDTH; ++xCord)
            {
                screen.setPixel(xCord, yCord, i, 0, j);
            }
        }

        screen.setPixel(400, 300, 0, 255, 0);

        screen.update();

        if (!screen.processEvent())
        {
            break;
        }
    }

    screen.close();
    return 0;
}
