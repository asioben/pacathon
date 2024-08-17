FILES = ./src/main.c ./src/update.c ./src/engine.c ./src/textures.c 
FILES += ./src/ai.c ./src/timer.c ./src/gameOver.c ./sdl2_utility/texture.c 
FILES += ./sdl2_utility/utility.c ./sdl2_utility/time

INCLUDES = -I./SDL2/include -L./SDL2/lib -I./SDL2_ttf/include -L./SDL2_ttf/lib
INCLUDES += -I./SDL2_image/include -L./SDL2_image/lib

all: main

main:
     gcc -o main ${FILES} ${INCLUDES} -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

clean:
     rm main