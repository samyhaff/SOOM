#include "game.h"
#include "loadMap.h"
#include "math.h"

void init(game *game) 
{
    SDL_Init(SDL_INIT_VIDEO);

    game->window = SDL_CreateWindow("SOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, FPS_WIDTH + MAP_WIDTH, FPS_HEIGHT, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    loadMap("map", game);

    game->board.step = MAP_WIDTH / game->board.dim; // A AMELIORER

    game->player.x = MAP_WIDTH / 2;
    game->player.y = MAP_HEIGHT / 2;
    game->player.norm = 10;
    game->player.size = game->board.step / 5; 
    game->player.angle = 0;
    game->player.dx = game->player.norm * cos(game->player.angle);
    game->player.dy = game->player.norm * sin(game->player.angle);

    game->done = false;
}
