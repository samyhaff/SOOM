#include "game.h"
#include <iostream>

using namespace std;

void draw(game *game)
{
    // clear the screen
    SDL_SetRenderDrawColor(game->renderer, 72, 72, 72, 255);
    SDL_RenderClear(game->renderer);

    SDL_Rect mapViewport = {FPS_WIDTH, 0, MAP_WIDTH, MAP_HEIGHT};
    SDL_RenderSetViewport(game->renderer, &mapViewport);

    // draw the map
    for (int i = 0; i < game->board.dim; i++)
    {
        for (int j = 0; j <= game->board.dim; j++)
        {
            if (game->board.arr[i][j] == WALL)
                SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
            else 
                SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
            SDL_Rect cell_rect = {j * game->board.step, i * game->board.step, game->board.step - 2, game->board.step - 2};
            SDL_RenderFillRect(game->renderer, &cell_rect);
        }
    }

    // draw the player
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
    SDL_Rect player_rect = {(int) game->player.x, (int) game->player.y, game->player.size, game->player.size};
    SDL_RenderFillRect(game->renderer, &player_rect);

    // draw the rays
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
    int x = (int) game->player.x + (game->player.size / 2);
    int y = (int) game->player.y + (game->player.size / 2);
    SDL_RenderDrawLine(game->renderer, x, y, x + game->player.norm * game->player.dx, y + game->player.norm * game->player.dy);
    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
    for (int i = 0; i < NB_RAYS; i++)
        SDL_RenderDrawLine(game->renderer, x, y, game->rays[i].x, game->rays[i].y);

    SDL_Rect fpsViewport = {0, 0, FPS_WIDTH, FPS_HEIGHT};
    SDL_RenderSetViewport(game->renderer, &fpsViewport);

    for (int i = 0; i < NB_RAYS; i++)
    {
        if (game->lights[i])
            SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
        else 
            SDL_SetRenderDrawColor(game->renderer, 122, 0, 0, 255);
        int offset = (FPS_HEIGHT / 2) - game->heights[i];
        SDL_Rect wall = {i * FPS_WIDTH / NB_RAYS, offset, FPS_WIDTH / NB_RAYS, (int) game->heights[i]};
        SDL_RenderFillRect(game->renderer, &wall);
    }

    SDL_RenderPresent(game->renderer);
}
