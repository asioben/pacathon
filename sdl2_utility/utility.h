#ifndef UTILITY_H
#define UTILITY_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#define HEIGHT 600
#define WIDTH 800

void safe_exit(char *error, SDL_Window *window, SDL_Renderer *renderer);

int in_string(char *string, char x);

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    WHITE,
    BLACK,
}Colors;

SDL_Color get_color(Colors color);

char *int_to_string(int number);

int in(int *array, int x);

char *string_concatenate(char *stringA, char *stringB);

int random(int min, int max);

#endif