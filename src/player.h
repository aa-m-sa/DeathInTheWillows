#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} MoveDirection;
/* public functions for player char related stuff */

void createPlayer(Game *game);

void movePlayer(Game *game, MoveDirection dir);


#endif // player.h
