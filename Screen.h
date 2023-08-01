//
// Created by ozgur on 7/27/2023.
//

#ifndef SDL_PARTICLEFIRESIMULATION_SCREEN_H
#define SDL_PARTICLEFIRESIMULATION_SCREEN_H

#include <SDL.h>

class Screen {
public:
    const static int SCREEN_WIDTH = 800; // const -> value cannot be changed, static -> common variable in every objects
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *buffer;
    Uint32 *bufferBlur;

public:
    Screen();

    bool init();
    bool processEvent();
    void setPixel(int xCord, int yCord, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void close();
    void boxBlur();
};


#endif //SDL_PARTICLEFIRESIMULATION_SCREEN_H
