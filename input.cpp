#include "game.h"

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
                }
            }
        }
    }
}
