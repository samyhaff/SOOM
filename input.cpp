#include "game.h"
#include "logic.h"
#include "math.h"

void input(game *game) 
{
    while (SDL_PollEvent(&game->e))
    {
        switch (game->e.type)
        {
            case SDL_QUIT:
                game->done = true;
            break;
            case SDL_KEYDOWN:
            {
                switch (game->e.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->done = true;
                    break;
                    case SDLK_UP:
                        if (canMoveUp(game))
                            up(game);
                    break;
                    case SDLK_DOWN:
                        if (canMoveDown(game))
                        down(game);
                    break;
                    case SDLK_RIGHT:
                        right(game);
                    break;
                    case SDLK_LEFT:
                        left(game);
                    break;
                }
            }
        }
    }
}
