#include "game.h"
#include "loadMap.h"

void init(game *game) 
{
    SDL_Init(SDL_INIT_VIDEO);

    game->window = SDL_CreateWindow("SOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    game->player.x = SCREEN_WIDTH / 2;
    game->player.y = SCREEN_HEIGHT / 2;
   game->player.velocity = 10;

    loadMap("map", game);

    game->board.xStep = SCREEN_WIDTH / game->board.w; // A AMELIORER
    game->board.yStep = SCREEN_HEIGHT / game->board.h;
    game->player.size = game->board.xStep / 5; 
    
    game->done = FALSE;
}
