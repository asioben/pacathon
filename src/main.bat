@echo off

set SDL2_include=..\SDL2\include
set SDL2_lib=..\SDL2\lib
set image_include=..\SDL2_image\include
set image_lib=..\SDL2_image\lib
set ttf_include=..\SDL2_ttf\include
set ttf_lib=..\SDL2_ttf\lib

set utility=..\sdl2_utility\utility.c
set texture=..\sdl2_utility\texture.c
set time=..\sdl2_utility\time.c

gcc main.c update.c engine.c textures.c ai.c timer.c gameOver.c %texture% %utility% %time% -I%SDL2_include% -L%SDL2_lib% -I%ttf_include% -L%ttf_lib% -I%image_include% -L%image_lib% -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -o main

main.exe