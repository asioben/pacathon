#ifndef GAMEOVER_H
#define GAMEOVER_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "engine.h"
#include "ai.h"

void initialization(Player *player, Entity *entities, SDL_Point *destination);

void gameOver(SDL_Renderer *renderer, Player *player, Entity *entities, int *animation_timer, int *counter);

#endif 