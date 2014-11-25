/* visual output implementation*/
#include <stdio.h>
#include "print.h"

char mapChar(Level *level, unsigned int x, unsigned int y)
{
    Map *map = &level->map;
    char c = '?';
    switch(map->tile[y][x]) {
    case TILE_WALL:
            c = '#';
            break;
    case TILE_OPEN:
            c = '.';
            break;
    case TILE_ROOM:
            c = '.';
            break;
    }

    return c;
}

void printLevel(Level *level)
{
    Map *map = &level->map;
    // print the whole of map background
    for (unsigned int i = 0; i < map->mapHeight; ++i) {
        for (unsigned int j = 0; j < map->mapWidth; ++j) {
            char c = mapChar(level, j, i);
            printf("%c", c);
        }
        printf("\n");
    }
}

void printVisuals(Game *game)
{
    Level *curLevel = game->currentLevel;
    if (game->opts.showAll) {
        printLevel(curLevel);
    }
}
