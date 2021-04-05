#include "game.h"
#include "logic.h"

void input(game *game) 
{
    while (SDL_PollEvent(&game->e))
    {
        switch (game->e.type)
        {
            case SDL_QUIT:
                game->done = TRUE;
            break;
            case SDL_KEYDOWN:
            {
                switch (game->e.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->done = TRUE;
                    break;
                    case SDLK_UP:
                    {
                        if (canMove(game, game->player.x, game->player.y -1))
                            game->player.y -= game->player.velocity;
                    }
                    break;
                    case SDLK_DOWN:
                    {
                        if (canMove(game, game->player.x, game->player.y + 1)) 
                            game->player.y += game->player.velocity;
                    }
                    break;
                    case SDLK_RIGHT:
                    {
                        if (canMove(game, game->player.x + 1, game->player.y)) 
                            game->player.x += game->player.velocity;
                    }
                    break;
                    case SDLK_LEFT:
                    {
                        if (canMove(game, game->player.x - 1, game->player.y)) 
                            game->player.x -= game->player.velocity;
                    }
                    break;
                }
            }
        }
    }
}
