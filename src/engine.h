#ifndef ENGINE_H
#define ENGINE_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "textures.h"

typedef struct player_{
    SDL_Rect rect;
    SDL_Point direction;
    TextureType type;

} Player;

void initializePlayer(Player *player);

int pathFinding(Player *player, SDL_Point mouse);

int collision(SDL_Rect *rectA, SDL_Rect *rectB);

void movement(Player *player);

#endif