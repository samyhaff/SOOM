#include "loadMap.h"
#include <fstream>
#include <iostream>

using namespace std;

void loadMap(string nameOfFile, game *game)
{
    fstream file;
    file.open(nameOfFile, ios::in);

    file >> game->board.dim;

    for (int i = 0; i < game->board.dim; i++)
    {
        for (int j = 0; j < game->board.dim; j++) 
        {
            file >> game->board.arr[i][j];
        }
    }

    file.close();
}
