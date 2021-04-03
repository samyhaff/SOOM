#ifndef GAME
#define GAME

#include <SDL2/SDL.h>

#define TRUE  1
#define FALSE 0

#define SREEN_WIDTH   1920
#define SCREEN_HEIGHT 1080

#define BOARD_MAX_WIDTH   100
#define BOARD_MAX_HEIGHT  100

#define EMPTY 0
#define WALL  1

#define N 100

typedef int board_array[BOARD_MAX_WIDTH][BOARD_MAX_HEIGHT];

typedef struct {
    int w, h;
    board_array arr;
} t_board;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event e;
    int done;
    t_board board;
} game;

#endif
