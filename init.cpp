#include "init.h"

void init(game *game) 
{
    SDL_Init(SDL_INIT_VIDEO);

    game->window = SDL_CreateWindow("SOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SREEN_WIDTH, SCREEN_HEIGHT, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    loadMap("word", game);
    
    game->done = FALSE;
}
