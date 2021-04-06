#ifndef GAME
#define GAME

#include <SDL2/SDL.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800

#define BOARD_MAX_DIM 100

#define PI 3.14159

#define EMPTY 0
#define WALL  1

#define FIELD_OF_VIEW PI / 4
#define NB_RAYS 100

typedef int board_array[BOARD_MAX_DIM][BOARD_MAX_DIM];

typedef struct {
    int dim, step;
    board_array arr;
} t_board;

typedef struct {
    float x, y, dx, dy, angle, norm;
    int size;
} t_player;

typedef struct {
   float x, y;
} t_ray;

typedef t_ray t_rays[NB_RAYS];

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event e;
    bool done;
    t_board board;
    t_player player;
    t_rays rays;
} game;

#endif
