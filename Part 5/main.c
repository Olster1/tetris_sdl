#include "./SDL2/sdl.h"
#include "stdbool.h"
#include "assert.h"

typedef struct {
	bool isFilled;
	// float r;
	// float g;
	// float b
} BoardVal;

typedef struct {
	int x;
	int y;
} ShapePos;

ShapePos initShapePos(int x, int y) {
	ShapePos result;
	result.x = x;
	result.y = y;
	return result;
}

typedef struct {
	ShapePos positions[4];
} ActiveShape;

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 10
#define BOARD_DIM 50
typedef struct {
	BoardVal board[BOARD_HEIGHT][BOARD_WIDTH];
	ActiveShape shape;
} GameData;

GameData initilizeGame() {
	GameData data;
	memset(&data, 0, sizeof(data));
	data.shape.positions[0] = initShapePos(1, 0);
	data.shape.positions[1] = initShapePos(2, 0);
	data.shape.positions[2] = initShapePos(3, 0);
	data.shape.positions[3] = initShapePos(4, 0);
	return data;
}

void RenderBoard(GameData *data, SDL_Renderer *renderer) {

	for(int y = 0; y < BOARD_HEIGHT; y++) {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			BoardVal val = data->board[y][x];

			SDL_Rect rect;
			rect.x = x*BOARD_DIM;
			rect.y = y*BOARD_DIM;
			rect.w = BOARD_DIM;
			rect.h = BOARD_DIM;
			SDL_SetRenderDrawColor(renderer,
		                       0, 
		                       0, 
		                       0,
		                       255);

			SDL_RenderDrawRect(renderer,
			                       &rect);
		}
	}
}

void RenderShape(ActiveShape *shape, SDL_Renderer *renderer) {
	for(int i =0 ; i < 4; i++) {
		ShapePos pos = shape->positions[i];
		SDL_Rect rect;
		rect.x = pos.x*BOARD_DIM;
		rect.y = pos.y*BOARD_DIM;
		rect.w = BOARD_DIM;
		rect.h = BOARD_DIM;
		SDL_SetRenderDrawColor(renderer,
	                       255, 
	                       0, 
	                       0,
	                       255);

		SDL_RenderFillRect(renderer,
		                       &rect);
	}

}
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

    GameData data = initilizeGame();
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
    	RenderShape(&data.shape, renderer);
    	RenderBoard(&data, renderer);
    	
    	SDL_RenderPresent(renderer);

    }
	return 0;
}