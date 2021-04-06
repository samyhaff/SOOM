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

float distance(float ax, float ay, float bx, float by)
{
    return sqrt((bx -ax) * (bx - ax) + (by - ay) * (by - ay));
}

void rayCasting(game *game) 
{
    float angle = game->player.angle - FIELD_OF_VIEW;
    int depth;
    float x_horizontal, y_horizontal, x_vertical, y_vertical, x_offset, y_offset;
    float inv_tan, neg_tan;
    int max_depth = SCREEN_HEIGHT / game->board.step;
    float angle_step = 2 * FIELD_OF_VIEW / NB_RAYS;

    // horizontal lines

    for (int i = 0; i < NB_RAYS; i++)
    {
        angle += angle_step;
        depth = 0;
        inv_tan = -1 / tan(angle);
        neg_tan = -tan(angle);

        // looking down
        if (angle > PI)
        {
            y_horizontal = ((int) game->player.y / game->board.step) * game->board.step - 1;
            x_horizontal = (game->player.y - y_horizontal) * inv_tan + game->player.x;
            y_offset = -game->board.step;
            x_offset = -y_offset * inv_tan;
        }
        // looking up
        else if (angle < PI)
        {
            y_horizontal = ((int) game->player.y / game->board.step) * game->board.step + game->board.step;
            x_horizontal = (game->player.y - y_horizontal) * inv_tan + game->player.x;
            y_offset = game->board.step;
            x_offset = -y_offset * inv_tan;
        }
        // looking horizontally
        else if  (angle == 0 || angle == PI)
        {
            x_horizontal = game->player.x;
            y_horizontal = game->player.y;
            depth = max_depth;
        }
        while (depth < max_depth)
        {
            if ((0 <= y_horizontal) && (0 <= x_horizontal) && (x_horizontal < SCREEN_WIDTH) && (y_horizontal < SCREEN_HEIGHT) 
                && (game->board.arr[(int) y_horizontal / game->board.step][(int) x_horizontal / game->board.step] == WALL))
            {
                depth = max_depth;
            }
            else 
            {
                x_horizontal += x_offset;
                y_horizontal += y_offset;
                depth += 1;
            }
        }

        // vertical lines

        depth = 0;
        // looking left
        if (angle > PI / 2 && angle < 3 * PI / 2)
        {
            x_vertical = ((int) game->player.x / game->board.step) * game->board.step - 1;
            y_vertical = (game->player.x - x_vertical) * neg_tan + game->player.y;
            x_offset = -game->board.step;
            y_offset = -x_offset * neg_tan;
        }
        // looking right
        else if (angle < PI / 2 || angle > 3 * PI / 2)
        {
            x_vertical = ((int) game->player.x / game->board.step) * game->board.step + game->board.step;
            y_vertical = (game->player.x - x_vertical) * neg_tan + game->player.y;
            x_offset = game->board.step;
            y_offset = -x_offset * neg_tan;
        }
        // looking vertically
        else if  (angle == PI / 2 || angle == 3 * PI / 2)
        {
            x_vertical = game->player.x;
            y_vertical = game->player.y;
            depth = max_depth;
        }
        while (depth < max_depth)
        {
            if ((0 <= y_vertical) && (0 <= x_vertical) && (x_vertical < SCREEN_WIDTH) && (y_vertical < SCREEN_HEIGHT) 
                && (game->board.arr[(int) y_vertical / game->board.step][(int) x_vertical / game->board.step] == WALL))
            {
                depth = max_depth;
            }
            else 
            {
                x_vertical += x_offset;
                y_vertical += y_offset;
                depth += 1;
            }
        }

        if (distance(game->player.x, game->player.y, x_horizontal, y_horizontal) < distance(game->player.x, game->player.y, x_vertical, y_vertical))
        {
            game->rays[i].x = x_horizontal;
            game->rays[i].y = y_horizontal;
        }
        else 
        {
            game->rays[i].x = x_vertical;
            game->rays[i].y = y_vertical;
        }
    }
}
