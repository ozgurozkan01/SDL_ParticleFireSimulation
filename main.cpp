#include <SDL.h>
#include <iostream>
#include <math.h>
#include "Screen.h"

int main(int argc, char *argv[])
{

    Screen screen;

    if (!screen.init())
    {
        std::cout << "Error initialising SDL!!" << std::endl;
        return -1;
    }

    while(true)
    {

        int elapsedTime = SDL_GetTicks(); // Time between program start and end or running time

        /*
         * sin(x) : returning value between -1 and 1
         * 1 + sin(x) : returning value between 0 and 2 (Cause color value cannot be minus)
         * 1 + sin(x * 0.0001) : Making the value change more slowly and smoothly between 0-2.
         * (1 + sin(x * 0.0001)) * 128 : returnin value between 0-255 (Color Range)
         * */
        unsigned char red = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0001)) * 128);
        unsigned char green = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0002)) * 128);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0003)) * 128);

        for (int yCord = 0; yCord < Screen::SCREEN_HEIGHT; ++yCord)
        {
            for (int xCord = 0; xCord < Screen::SCREEN_WIDTH; ++xCord)
            {
                screen.setPixel(xCord, yCord, red, green, blue);
            }
        }

        screen.update();

        if (!screen.processEvent())
        {
            break;
        }
    }

    screen.close();
    return 0;
}
