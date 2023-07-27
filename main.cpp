#include <SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    bool isQuit = false;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL init failed." << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_Quit();
        return -2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -3;
    }

    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH,
                                             SCREEN_HEIGHT);

    if (texture == nullptr)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -4;
    }

    // Buffer is gonna be used for storing the pixel in it.
    // We are storing pixels, cause otherwise view on the screen can be seen incorrect, irregular
    // Storing data set the pixel as convenient and useable.
    Uint32 *buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH]; // All pixels are 32 bit RGBA8888, and we have SCREEN_WIDTH * SCREEN_HEIGHT pixels                                                               SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32)); // Update texture (pixels) via buffer (pixel container)

    memset(buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer); // Clear renderer which render the data its stored.
    SDL_RenderCopy(renderer, texture, nullptr, nullptr); // Fill the renderer via texture
    SDL_RenderPresent(renderer); // Show the data that renderer holds.

    while(!isQuit)
    {

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                isQuit = true;
            }
        }
    }

    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); // we need to delete pointer, otherwise it keeps going to allocate memory
    SDL_Quit();
    return 0;
}
