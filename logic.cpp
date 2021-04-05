#include "game.h"

int canMove(game *game, int x, int y)
{
    return ((game->board.arr[(x + game->player.size / 2) / game->board.xStep][(y + game->player.size / 2) / game->board.yStep] == EMPTY) && (0 <= x) && (0 <= y) && (x < SCREEN_WIDTH - game->player.size) && (y < SCREEN_HEIGHT - game->player.size));
}
