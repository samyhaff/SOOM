#include "game.h"

void draw(game *game)
{
    // clear the screen
    SDL_SetRenderDrawColor(game->renderer, 128, 128, 128, 255);
    SDL_RenderClear(game->renderer);

    // draw the map
    for (int i = 0; i < game->board.h; i++)
    {
        for (int j = 0; j <= game->board.w; j++)
        {
            if (game->board.arr[i][j] == WALL)
                SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
            else 
                SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
            SDL_Rect cell_rect = {j * game->board.xStep, i * game->board.yStep, game->board.xStep - 2, game->board.yStep - 2};
            SDL_RenderFillRect(game->renderer, &cell_rect);
        }
    }

    // draw the player
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
    SDL_Rect player_rect = {game->player.x, game->player.y, game->player.size, game->player.size};
    SDL_RenderFillRect(game->renderer, &player_rect);

    SDL_RenderPresent(game->renderer);
}