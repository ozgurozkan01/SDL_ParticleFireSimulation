//
// Created by ozgur on 7/27/2023.
//

#include "Screen.h"
#include <iostream>

Screen::Screen() :
    window(nullptr), renderer(nullptr), texture(nullptr), buffer(nullptr), bufferBlur(nullptr)// initializer list method
{

}

bool Screen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }

    window = SDL_CreateWindow("Particle Fire Explosion",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH,
                                             SCREEN_HEIGHT);

    if (texture == nullptr)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    // Buffer is gonna be used for storing the pixel in it.
    // We are storing pixels, cause otherwise view on the screen can be seen incorrect, irregular
    // Storing data set the pixel as convenient and useable without breakdown.
    buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH]; // All pixels are 32 bit RGBA8888, and we have SCREEN_WIDTH * SCREEN_HEIGHT pixels                                                               SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32)); // Update texture (pixels) via buffer (pixel container)
    bufferBlur = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(bufferBlur, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
}

bool Screen::processEvent()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;
}

void Screen::close()
{
    delete [] buffer;
    delete [] bufferBlur;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); // we need to delete pointer, otherwise it keeps going to allocate memory
    SDL_Quit();
}

void Screen::setPixel(int xCord, int yCord, Uint8 red, Uint8 green, Uint8 blue)
{
    // Pixel is 32 bit, Cause pixel has 3 colors and 1 opacity-transparency
    // Color is 8 bit, Cause color can be index between 0-255
    Uint32 color = 0;

    if (xCord < 0 || xCord >= SCREEN_WIDTH || yCord < 0 || yCord >= SCREEN_HEIGHT)
    {
        return;
    }

    color += red; // 0xFF = color
    color <<= 8;
    color += green; // 0xFF4D = color
    color <<= 8;
    color += blue; // 0xFF4D8A = color
    color <<= 8;
    color += 0xFF; // 0xFF4D8AFF = color

    // We have as much width as height.
    // yCord represents particular point of Height.
    // xCord represents particular point of Width.
    buffer[(yCord * SCREEN_WIDTH) + xCord] = color;
}

void Screen::update()
{
    SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer); // Clear renderer which render the data its stored.
    SDL_RenderCopy(renderer, texture, nullptr, nullptr); // Fill the renderer via texture
    SDL_RenderPresent(renderer); // Show the data that renderer holds.
}

void Screen::boxBlur()
{
    Uint32 *temp = buffer;
    buffer = bufferBlur;
    bufferBlur = temp;

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            /* 3x3 filter is a filter used to take the pixel values of 8 pixels neighbouring a pixel and calculate the average.
             * 0 0 0
             * 0 1 0
             * 0 0 0
             * */

            // Store the color amount of 9 neighbooring colors
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;


            // To navigate the 3x3 filter
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int currentX = x + col;
                    int currentY = y + row;

                    if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT)
                    {
                        Uint32 color = bufferBlur[currentY * SCREEN_WIDTH + currentX];

                        // Bit shifting and then store 8 bit for colors
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }

            Uint8 red = redTotal / 9;
            Uint8 green = greenTotal / 9;
            Uint8 blue = blueTotal / 9;

            setPixel(x, y, red, green, blue);
        }
    }
}