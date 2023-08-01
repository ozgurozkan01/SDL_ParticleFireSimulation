#include <SDL.h>
#include <time.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Screen screen;
    Swarm swarm;

    srand(time(nullptr));

    if (!screen.init())
    {
        return -1;
    }

    while(true)
    {

        int elapsedTime = SDL_GetTicks(); // Time between program start and end or running time

        //screen.clear();
        swarm.update(elapsedTime);

        /*
         * sin(x) : returning value between -1 and 1
         * 1 + sin(x) : returning value between 0 and 2 (Cause color value cannot be minus)
         * 1 + sin(x * 0.0001) : Making the value change more slowly and smoothly between 0-2.
         * (1 + sin(x * 0.0001)) * 128 : returnin value between 0-255 (Color Range)
         * */
        unsigned char red = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0001)) * 128);
        unsigned char green = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0002)) * 128);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsedTime * 0.0003)) * 128);

        const Particle* const particles = swarm.getParticles();

        if (particles == nullptr)
        {
            return -2;
        }

        for (int i = 0; i < Swarm::NPARTICLES; ++i)
        {
            Particle particle = particles[i];

            // Screen borders scaled by 0 and 1. For this reason, 0.5 center of the screen.
            // If we want to place the particle on border, we need a value 0 or 1
            int x = static_cast<int>((particle.getX() + 0.5) * Screen::SCREEN_WIDTH / 2);
            int y = static_cast<int>((particle.getY() - 0.5 )* Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2);

            screen.setPixel(x, y, red, green, blue);
        }

        screen.boxBlur();
        screen.update();

        if (!screen.processEvent())
        {
            break;
        }
    }

    screen.close();
    return 0;
}
