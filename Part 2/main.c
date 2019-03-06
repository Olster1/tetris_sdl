#include "./SDL2/sdl.h"
#include "stdbool.h"

int main(int argc, char **args) {
	int width = 400;
	int height = 800;
	SDL_Window* window = SDL_CreateWindow("Tetris",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             width,
                             height,
                             0);
    bool running = true;
    while(running) {
    	SDL_Event event;
    	while(SDL_PollEvent(&event)) {
    		if(event.type == SDL_QUIT) {
    			running = false;
    		}
    	}

    }
	return 0;
}