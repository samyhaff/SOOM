#ifndef LOGIC
#define LOGIC

#include "game.h"

void left(game *game);
void right(game *game);
void up(game *game);
void down(game *game);
void rayCasting(game *game);
bool canMoveUp(game *game);
bool canMoveDown(game *game);

#endif
