#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "game.h"

void generateMap(Level *level)
{
    Map *map = &level->map;
    // hardcoded map size, not good
    unsigned int height = 10;
    unsigned int width = 20;
    map->mapHeight = height;
    map->mapWidth = width;
    map->tile = malloc(sizeof(Tile *) * height);

    // initial fill
    for (unsigned int i = 0; i < height; ++i) {
        map->tile[i] = malloc(sizeof(Tile) * width);
        for (unsigned int j = 0; j < width; ++j) {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
                map->tile[i][j] = TILE_WALL;
            } else {
                map->tile[i][j] = TILE_ROOM;
            }
        }
    }

}

Level *createLevel(char *name)
{
    // set the name for the level
    Level *level = malloc(sizeof(Level));
    strncpy(level->name, name, 20);

    // monsters: 0
    level->numMonsters = 0;
    level->monsters = NULL;

    // map
    generateMap(level);

    return level;
}


void generateLevels(Game *game)
{
    // levels list
    // make space for just one level in the list for testing
    unsigned int numLevels = 1;
    game->numLevels = numLevels;
    game->levels = malloc(numLevels * sizeof(Level *));

    // populate it with default level
    char *name = "default";
    game->levels[0] = createLevel(name);
}

void freeLevel(Level *level)
{
    if (level->monsters)
        free(level->monsters);

    if (level->map.tile){
        for (unsigned int i = 0; i < level->map.mapHeight; i++) {
            free(level->map.tile[i]);
        }
        free(level->map.tile);
    }

    free(level);
}

void freeAll(Game *game)
{
    if(game->levels) {
        // remove levels
        for (unsigned int i = 0; i < game->numLevels; i++) {
            freeLevel(game->levels[i]);
        }
        game->numLevels = 0;
        free(game->levels);
    }

}

