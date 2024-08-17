#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "utility.h"
#include "texture.h"
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>

SDL_Texture* loadImg(SDL_Renderer *renderer,char *path){
    if(in_string(path,'.') == 0) return NULL;
    SDL_Surface *img = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,img);
    SDL_FreeSurface(img);
    return texture;
}

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
}

int print(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color color, char *path, const char *text){
    if(TTF_Init() == -1) return 0;
    TTF_Font *font = TTF_OpenFont(path,25);
    if(font == 0) return 0;
    SDL_Surface *surface = TTF_RenderText_Blended(font,text,color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer,texture,NULL,rect);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    TTF_Quit();
    //SDL_RenderPresent(renderer);
    return 1;
}