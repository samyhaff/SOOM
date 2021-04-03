#include "quit.h"

void quit(game *game) 
{
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    
    SDL_Quit();
}
