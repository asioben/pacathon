#ifndef TEXTURE_H
#define TEXTURE_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "utility.h"
#include <SDL2_ttf/SDL_ttf.h>

SDL_Texture* loadImg(SDL_Renderer *renderer,char *path);

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture);

int print(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color color, char *path, const char *text);

#endif
