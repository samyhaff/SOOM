#include "loadMap.h"
#include <fstream>
#include <iostream>

using namespace std;

void loadMap(string nameOfFile, game *game)
{
    fstream file;
    file.open(nameOfFile, ios::in);

    file >> game->board.w;
    file >> game->board.h;

    for (int i = 0; i < game->board.h; i++)
    {
        for (int j = 0; j < game->board.w; j++) 
        {
            file >> game->board.arr[i][j % game->board.w];
        }
    }

    file.close();
}
