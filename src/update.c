#include "update.h"
#include "../sdl2_utility/texture.h"
#include "../sdl2_utility/utility.h"

void getFlip(Player *player, SDL_RendererFlip *flip, double *angle){
    if(player->direction.x > 0){
        *flip = SDL_FLIP_NONE;
        *angle = 0;
        player->direction.x = 0;
    }
    else if(player->direction.x < 0){
        *flip = SDL_FLIP_HORIZONTAL;
        *angle = 0;
        player->direction.x = 0;
    }else if(player->direction.y > 0){
        *flip = SDL_FLIP_NONE;
        *angle = 90;
        player->direction.y = 0;
    }else if(player->direction.y < 0){
        *flip = SDL_FLIP_HORIZONTAL;
        *angle = 90;
        player->direction.y = 0;
    }
    
}

void title(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *play, Entity *test, SDL_Point *mouse, int animation_timer){
    if(SDL_SetRenderDrawColor(renderer,0,0,0,0) != 0)
     safe_exit("Error of color",NULL,renderer);

    SDL_RenderClear(renderer);

    SDL_Rect src[4],drt;
    SDL_Color color[3] = {
        {237,28,36,0}, 
        {34,177,76,0}, 
        {63,72,204,0},    
    };

    drt.x = 375;
    drt.y = 250;
    drt.w = 50;
    drt.h = 50;

    if(animation_timer % 2 == 1) getTexture(CLOSE,&src[0]);
    else getTexture(OPEN,&src[0]);

    if(SDL_PointInRect(mouse,play))print(renderer,play,get_color(GREEN),"../font/font.ttf","PLAY");
    else if(animation_timer %2 == 1) print(renderer,play,get_color(RED),"../font/font.ttf","PLAY");
    else print(renderer,play,get_color(BLUE),"../font/font.ttf","PLAY");

    SDL_RenderCopy(renderer,texture,&src,&drt);

    for(int i = 0 ; i < 3; i++){
        if(animation_timer % 3 == 0){
            getTexture(test[i].entity.type, &src[i+1]);

            if(animation_timer % 3 == 1) 

            test[i].entity.direction.x = 0;
            test[i].entity.direction.y = 0;

            SDL_RenderCopy(renderer,texture,&src[i+1],&test[i].entity.rect);
        }else{
            SDL_Rect entity = {test[i].entity.rect.x,test[i].entity.rect.y,50,50};
            if(SDL_SetRenderDrawColor(renderer,color[i].r,color[i].g,color[i].b,0) != 0)
                safe_exit("Error of color",NULL,renderer);

            if(SDL_RenderFillRect(renderer,&entity) != 0)
                safe_exit("Error of rendering rectangles",NULL,renderer);
        }
    }

    SDL_RenderPresent(renderer);

}

void update(SDL_Renderer *renderer, SDL_Texture *texture, Player *player, Entity *entities, int animation_timer, int counter){
    if(SDL_SetRenderDrawColor(renderer,0,0,0,0) != 0)
     safe_exit("Error of color",NULL,renderer);

    SDL_RenderClear(renderer);

    SDL_Rect src[4],counter_;
    SDL_RendererFlip flip;
    SDL_Color color[3] = {
        {237,28,36,0}, 
        {34,177,76,0}, 
        {63,72,204,0},    
    };
    double angle;

    counter_.x = 450;
    counter_.y = 0;
    counter_.w = 100;
    counter_.h = 100;

    getTexture(player->type,&src[0]);
    getFlip(player,&flip,&angle);

    if(animation_timer %2 == 1) player->type = OPEN;
    else player->type = CLOSE;

    SDL_RenderCopyEx(renderer,texture,&src[0],&player->rect,angle,NULL,flip);

    for(int i = 0; i < 3; i++){
        if(entities[i].alive == 0){
            if(entities[i].entity.type == AI_0 + i){
                getTexture(entities[i].entity.type,&src[i+1]);
                SDL_RenderCopy(renderer,texture,&src[i+1],&entities[i].entity.rect);     
            }else{
                SDL_Rect entity = {entities[i].entity.rect.x,entities[i].entity.rect.y,50,50};
                if(SDL_SetRenderDrawColor(renderer,color[i].r,color[i].g,color[i].b,0) != 0)
                 safe_exit("Error of color",NULL,renderer);

                if(SDL_RenderFillRect(renderer,&entity) != 0)
                 safe_exit("Error of rendering rectangles",NULL,renderer);
            }
            if(animation_timer % 3 == 1) entities[i].entity.type = CLOSE;
            else entities[i].entity.type = AI_0 + i;
        }else{
            SDL_Rect rect = {i*30+15,15,15,15};
            getTexture(AI_0 + i,&src[i+1]);
            SDL_RenderCopy(renderer,texture,&src[i+1],&rect);
        }
    }

    print(renderer,&counter_,get_color(WHITE),"../font/font.ttf",int_to_string(counter));

    SDL_RenderPresent(renderer);
}