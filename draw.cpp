#include "game.h"

void draw(game *game)
{
    // clear the screen
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    // draw the map
    int xStep = SCREEN_WIDTH / game->board.w;
    int yStep = SCREEN_HEIGHT / game->board.h;
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    for (int i = 0; i < game->board.h; i++)
    {
        for (int j = 0; j <= game->board.w; j++)
        {
            if (game->board.arr[i][j] == 1)
            {
                SDL_Rect cell_rect = {j * xStep, i * yStep, xStep, yStep};
                SDL_RenderFillRect(game->renderer, &cell_rect);
            }
        }
    }

    // draw the player
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_Rect player_rect = {game->player.x, game->player.y, PLAYER_HEIGHT, PLAYER_HEIGHT};
    SDL_RenderFillRect(game->renderer, &player_rect);

    SDL_RenderPresent(game->renderer);
}
