#include "time.h"

int counter(Uint32 before, Uint32 after, Uint32 time_elapsed){
    Uint32 elapsed_time = after-before;
    if(elapsed_time >= time_elapsed) return 1;
    return 0;
}