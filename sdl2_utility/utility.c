#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "utility.h"
#include <stdlib.h>

void safe_exit(char *error, SDL_Window *window, SDL_Renderer *renderer){
    printf("%s: %s\n",error, SDL_GetError());
    if(renderer != NULL) SDL_DestroyRenderer(renderer);
    if(window != NULL) SDL_DestroyWindow(window);
    SDL_Quit();
}

int in_string(char *string, char x){
    for(int i = 0; i < sizeof(string)/sizeof(x); i++){
        if(string[i] == x) return 1;
    }
    return 0;
}

SDL_Color get_color(Colors color){
    SDL_Color colour = {0,0,0,255};
    switch(color){
        case RED:
         colour.r = 255;
         return colour;
        case GREEN:
         colour.g = 255;
         return colour;
        case BLUE:
         colour.b = 255;
         return colour;
        case YELLOW:
         colour.r = 255;
         colour.g = 255;
         return colour;
        case ORANGE:
         colour.r = 255;
         colour.g = 165;
         return colour;
        case WHITE:
         colour.r = 255;
         colour.g = 255;
         colour.b = 255;
         return colour;
        case BLACK:
         return colour;
    }
}
    
char *int_to_string(int number){
    int nega = 0;
    if(number <= 0){
        if(number == 0) return "0";
        nega = 1;
        number *= -1;
    };
    int elements = SDL_floor(SDL_log10(number)) + 1;
    printf("%i\n",elements);
    char *string = malloc(sizeof(char)*(elements+1+nega));
    int j = elements-1;
    int k = 0;
    string[0] = '-';
    for(int i = nega; i < elements+nega; i++){
        k = number/pow(10,j);
        string[i] = k + '0';
        number = number - (k*(SDL_pow(10,j)));
        j -= 1;
    }
    string[elements + nega] = '\0';
    return string;
}

int in(int *array, int x){
    for(int i = 0; i < sizeof(array)/sizeof(int); i++){
        if(x == array[i]){
            return 1;
        }
    }
    return 0;
}

int string_length(char *string){
    int iteration = 0;

    while(string[iteration] != '\0'){
        iteration += 1;
    }

    return iteration + 1;
}

char *string_concatenate(char *stringA, char *stringB){
    int length[3];

    length[0] = string_length(stringA) - 1;
    length[1] = string_length(stringB);
    length[2] = length[0] + length[1];

    char *string = malloc(length[2]*sizeof(char));

    for(int i = 0; i < length[0]; i++){
        string[i] = stringA[i];
    }

    for(int j = length[0],k = 0; k < length[1]; j++, k++){
        string[j] = stringB[k];
    }

    string[length[2] - 1] = '\0';

    return string;

}

int random(int min, int max){
    int result,low,high = 0;

    if(min > max){
        low = max + 1;
        high = min;
    }else{
        low = min;
        high = max + 1;
    }

    result = (rand() % (high - low)) + low;

    return result;
}