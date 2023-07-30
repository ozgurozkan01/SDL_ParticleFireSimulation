//
// Created by ozgur on 7/27/2023.
//

#include "Screen.h"
#include <iostream>

Screen::Screen() :
    window(nullptr), renderer(nullptr), texture(nullptr), buffer(nullptr) // initializer list method
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

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

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

void Screen::clear()
{
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}
