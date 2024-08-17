#include "timer.h"
#include "../sdl2_utility/time.h"

void timer(Uint32 *before, Uint32 *after, Uint32 time_elapsed, int *animation_timer, int *counter_){
    *after = SDL_GetTicks();
    if(counter(*before,*after,time_elapsed) == 1){
        *animation_timer += 1;
        *before = SDL_GetTicks();
        *counter_ -= 1;
    }
}