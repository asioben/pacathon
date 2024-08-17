#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "../sdl2_utility/utility.h"
#include "update.h"
#include "engine.h"
#include <stdlib.h>
#include "../sdl2_utility/texture.h"
#include "textures.h"
#include "ai.h"
#include "gameOver.h"
#include "timer.h"
#include <time.h>

int main(){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_bool loop = SDL_TRUE;
    SDL_Rect play = {300,400,200,100};
    SDL_Rect blocks[56];
    SDL_Point mouse = {0,0};
    SDL_Point size = {11,11};
    SDL_Point destination[3];
    Player player;
    Entity entities[3],test[3];
    Uint32 before = SDL_GetTicks();
    Uint32 after = 0;
    int iteration = 0;
    int click = 0;
    int animation_timer = 0;
    int counter = 0;
    int game_over = 0;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
     safe_exit("Error of initialisation",window,renderer);

    if(SDL_CreateWindowAndRenderer(WIDTH,HEIGHT,0,&window,&renderer))
     safe_exit("Error of create window and renderer", window, renderer);

    texture = loadImg(renderer,"../sprite/sprite.png");

    srand(time(NULL));

    initialization(&player,entities,destination);
    
    for(int i = 0; i < 3; i++){
        initializeEntity(&test[i]);
        test[i].entity.type = AI_0 + i;
    }

   test[0].entity.rect.x = 325; 
   test[0].entity.rect.y = 150;

   test[1].entity.rect.x = 375; 
   test[1].entity.rect.y = 150;

   test[2].entity.rect.x = 425; 
   test[2].entity.rect.y = 150;

    while(loop){
        SDL_Delay(5);
        timer(&before,&after,500,&animation_timer,&counter);
        if(click == 0) title(renderer,texture,&play,test,&mouse,animation_timer);
        else{
            if(counter != 0 || game_over != 1 || entities[0].alive != 1) for(int k = 0; k < 3; k++) aiMovement(&entities[k],&destination[k]);
            pathFinding(&player,mouse);
            movement(&player);
            for(int j = 0; j < 3; j++) eat(&player,&entities[j],j,&game_over);
            if(counter < 0) counter = 100;
            if(counter == 0 || game_over == 1 || entities[0].alive == 1) gameOver(renderer,&player,entities,&animation_timer,&counter);
            else update(renderer,texture,&player,entities,animation_timer,counter);
        }
        SDL_SetWindowTitle(window,"PACSNAKE");
        SDL_Event event;
        while(SDL_PollEvent(&event) == 1){
            switch(event.type){
                case SDL_QUIT: loop = SDL_FALSE;break;
                case SDL_MOUSEBUTTONDOWN:
                 mouse.x = event.motion.x;
                 mouse.y = event.motion.y;
                 if(SDL_PointInRect(&mouse,&play)) click = 1;
                 if(counter == 0 || game_over == 1 || entities[0].alive == 1){
                    initialization(&player,entities,destination);
                    game_over = 0;
                    counter = 100;
                }
                 break;
                case SDL_MOUSEMOTION:
                 mouse.x = event.motion.x;
                 mouse.y = event.motion.y;
                 break;
            }
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}

// TODO

// FINISH TITLE SCREEN -=> FINISH, almost? I've started animation
// MAPPING -=> STARTS
// AI 
//MUSIC ETC
// CHECK CODE
// MAKEFILE/GITHUB