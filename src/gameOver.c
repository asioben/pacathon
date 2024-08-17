#include "gameOver.h"
#include "../sdl2_utility/texture.h"

void initialization(Player *player, Entity *entities, SDL_Point *destination){
    initializePlayer(player);
    player->rect.x = 250;
    player->rect.y = 300;

    for(int i = 0; i < 3; i++){
        destination[i].x = random(0,500);
        destination[i].y = random(0,500);

        destination[i].x = destination[i].x - (destination[i].x%50);
        destination[i].y = destination[i].y - (destination[i].y%50);

        initializeEntity(&entities[i]);
    }

    entities[0].entity.rect.x = 250;
    entities[0].entity.rect.y = 150;

    entities[1].entity.rect.x = 200;
    entities[1].entity.rect.y = 200;

    entities[2].entity.rect.x = 300;
    entities[2].entity.rect.y = 200;
}

void gameOver(SDL_Renderer *renderer, Player *player, Entity *entities, int *animation_timer, int *counter){
    if(SDL_SetRenderDrawColor(renderer,0,0,0,0) != 0)
     safe_exit("Error of color",NULL,renderer);

    SDL_RenderClear(renderer);

    SDL_Rect rect = {100,100,600,400};

    if(entities[0].alive == 1)print(renderer,&rect,get_color(BLUE),"../font/font.ttf","YOU WIN !!!");
    else print(renderer,&rect,get_color(RED),"../font/font.ttf","YOU LOSE !!!");

    SDL_RenderPresent(renderer);
}