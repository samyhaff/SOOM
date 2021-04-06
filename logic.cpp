#include "game.h"

void left(game *game) 
{
    game->player.angle -= 0.05;
    if (game->player.angle < 0)
        game->player.angle += 2 * PI;
    game->player.dx = game->player.norm * cos(game->player.angle);
    game->player.dy = game->player.norm * sin(game->player.angle);
}

void right(game *game) 
{
    game->player.angle += 0.05;
    if (game->player.angle > 2 * PI)
        game->player.angle -= 2 * PI;
    game->player.dx = game->player.norm * cos(game->player.angle);
    game->player.dy = game->player.norm * sin(game->player.angle);
}

void up(game *game) 
{
    game->player.x += game->player.dx;
    game->player.y += game->player.dy;
}

void down(game *game) 
{
    game->player.x -= game->player.dx;
    game->player.y -= game->player.dy;
}
