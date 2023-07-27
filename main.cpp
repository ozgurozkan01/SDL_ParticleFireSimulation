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


    while(true)
    {
        if (!screen.processEvent())
        {
            break;
        }
    }

    screen.close();
    return 0;
}
