#ifndef TEXTURES_H
#define TEXTURES_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

typedef enum{
    CLOSE,
    OPEN,
    AI_0,
    AI_1,
    AI_2
} TextureType;

void getTexture(TextureType type, SDL_Rect *src);

#endif