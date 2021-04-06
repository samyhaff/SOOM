#include "game.h"
#include <iostream>

using namespace std;

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

void rayCasting(game *game) 
{
    game->ray.angle = game->player.angle;

    for (int r = 0; r < 1; r++)
    {
        int depth = 0;
        float inv_tan = -1 / tan(game->ray.angle);
        int max_depth = SCREEN_HEIGHT / game->board.step;
        // looking down
        if (game->ray.angle > PI)
        {
            game->ray.y = ((int) game->player.y / game->board.step) * game->board.step - 0.001;
            game->ray.x = (game->player.y - game->ray.y) * inv_tan + game->player.x;
            game->ray.y_offset = -game->board.step;
            game->ray.x_offset = -game->ray.y_offset * inv_tan;
        }
        // looking up
        else if (game->ray.angle < PI && game->ray.angle != 0)
        {
            game->ray.y = ((int) game->player.y / game->board.step) * game->board.step + game->board.step;
            game->ray.x = (game->player.y - game->ray.y) * inv_tan + game->player.x;
            game->ray.y_offset = game->board.step;
            game->ray.x_offset = -game->ray.y_offset * inv_tan;
        }
        // looking horizontally
        else if  (game->ray.angle == 0 || game->ray.angle == PI)
        {
            game->ray.x = game->player.x;
            game->ray.y = game->player.y;
            depth = max_depth;
        }
        while (depth < max_depth)
        {
            if ((0 <= game->ray.y) && (0 <= game->ray.x) && (game->ray.x < SCREEN_WIDTH) && (game -> ray.y < SCREEN_HEIGHT) 
                && (game->board.arr[(int) game->ray.y / game->board.step][(int) game->ray.x / game->board.step] == WALL))
            {
                depth = max_depth;
            }
            else 
            {
                game->ray.x += game->ray.x_offset;
                game->ray.y += game->ray.y_offset;
                depth += 1;
            }
        }
    }
}
