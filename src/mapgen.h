#ifndef MAPGEN_H
#define MAPGEN_H

#include "game.h"

/* public functions for map generation (mapgen.c) */

/* generates leves to the Game*/
void generateLevels(Game *game);

/* free dynamically created memory*/
void freeAll(Game *game);


#endif // MAPGEN_H
