#ifndef AI_H
#define AI_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "engine.h"

typedef struct entity_{
    Player entity;
    int alive;
}Entity;

void initializeEntity(Entity *entities);

void eat(Player *player, Entity *entities, int index, int *game_over);

void aiMovement(Entity *entity, SDL_Point *destination);

#endif