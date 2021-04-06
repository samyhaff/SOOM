#include "game.h"
#include "init.h"
#include "input.h"
#include "draw.h"
#include "quit.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    game game;

    init(&game); 

    while (!game.done)
    {
        input(&game);
        rayCasting(&game);
        draw(&game);
    }

    quit(&game);

    return 0;
}
