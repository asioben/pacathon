#include "textures.h"

void getTexture(TextureType type, SDL_Rect *src){
    src->y = 0;
    src->h = 115;
    switch(type){
        case CLOSE:
         src->x = 0;
         src->w = 127;
         break;
        case OPEN:
         src->x = 130;
         src->w = 127;
         break;
        case AI_0:
         src->x = 280;
         src->w = 109;
         break;
        case AI_1:
         src->x = 400;
         src->w = 100;
         break;
        case AI_2:
         src->x = 516;
         src->w = 110;
         break;
    }
}