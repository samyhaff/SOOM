#include "game.h"

void draw(game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    SDL_RenderPresent(game->renderer);
}
