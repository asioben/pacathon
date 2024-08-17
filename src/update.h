#ifndef UPDATE_H
#define UPDATE_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "engine.h"
#include "textures.h"
#include "ai.h"

void title(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *play, Entity *test, SDL_Point *mouse, int animation_timer);

void update(SDL_Renderer *renderer, SDL_Texture *texture, Player *player, Entity *entities, int animation_timer, int counter);

#endif