#include "game.h"
#include "init.h"
#include "input.h"
#include "draw.h"
#include "quit.h"

int main(int argc, char *argv[])
{
    game game;

    init(&game); 

    while (!game.done)
    {
        draw(&game);
        input(&game);
    }

    quit(&game);

    return 0;
}
