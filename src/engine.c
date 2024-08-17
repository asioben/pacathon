#include "engine.h"

void initializePlayer(Player *player){
    player->rect.x = 0;
    player->rect.y = 0;
    player->rect.w = 50;
    player->rect.h = 50;

    player->direction.x = 0;
    player->direction.y = 0;

    player->type = CLOSE;
}

int pathFinding(Player *player, SDL_Point mouse){
    SDL_Point distance;
    SDL_Point position;

    distance.x = mouse.x - player->rect.x;
    distance.y = mouse.y - player->rect.y;

    position.x = player->rect.x/50;
    position.y = player->rect.y/50;

    if((distance.x == 0 && distance.y == 0)){
       return 0;
    }

    if(distance.x != 0){
        player->direction.x = (distance.x/SDL_abs(distance.x));
    }else if(distance.y != 0){
        player->direction.y = (distance.y/SDL_abs(distance.y));
    }
    
    return 1;
}

int collision(SDL_Rect *rectA, SDL_Rect *rectB){
    if((rectA->x <= rectB->x && rectB->x <= rectA->x + rectA->w) && ((rectA->y <= rectB->y && rectB->y <= rectA->y + rectA->h) || (rectB->y <= rectA->y && rectA->y <= rectB->y + rectB->h) )) return 1;
    else if((rectB->x <= rectA->x && rectA->x <= rectB->x + rectB->w) && ((rectA->y <= rectB->y && rectB->y <= rectA->y + rectA->h) || (rectB->y <= rectA->y && rectA->y <= rectB->y + rectB->h) )) return 1;
    return 0;
    
}

void movement(Player *player){
    player->rect.x += player->direction.x;
    player->rect.y += player->direction.y;
}