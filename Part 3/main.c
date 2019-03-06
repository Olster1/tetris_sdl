#include "./SDL2/sdl.h"
#include "stdbool.h"
#include "assert.h"

int main(int argc, char **args) {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		assert(false);
	}
	int width = 400;
	int height = 800;
	SDL_Window* window = SDL_CreateWindow("Tetris",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             width,
                             height,
                             0);
                      
     SDL_Renderer* renderer = SDL_CreateRenderer(window,
                                      -1,
                                      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bool running = true;
    while(running) {
    	SDL_Event event;
    	while(SDL_PollEvent(&event)) {
    		if(event.type == SDL_QUIT) {
    			running = false;
    		}
    	}

    	SDL_SetRenderDrawColor(renderer,
    	                           255,
    	                           255,
    	                           0,
    	                           255);

    	SDL_RenderClear(renderer);
    	SDL_Rect rect;
    	rect.x = 0;
    	rect.y = 0;
    	rect.w = 100;
    	rect.h = 100;
    	SDL_SetRenderDrawColor(renderer,
                           255, 
                           0, 
                           0,
                           255);

    	SDL_RenderFillRect(renderer,
    	                       &rect);
    	SDL_RenderPresent(renderer);

    }
	return 0;
}