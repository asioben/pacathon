#ifndef TIMER_H
#define TIMER_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

void timer(Uint32 *before, Uint32 *after, Uint32 time_elapsed, int *animation_timer, int *counter_);

#endif