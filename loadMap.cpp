#include "loadMap.h"
#include <fstream>

using namespace std;

void loadMap(string nameOfFile, game *game)
{
    fstream file;
    int var;
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
