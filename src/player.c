#include <string.h>
#include "game.h"
#include "player.h"

void createPlayer(Game *game)
{
    Creature *player = &game->player;

    char *name = "player";
    strncpy(player->name, name, 20);
    player->sign = '@';
    player->hp = 100.0;
    player->maxhp = 100;

    player->playerControl = 1;
    player->pos.x = 5;
    player->pos.y = 5;

}

/* consider moving collision detection somewhere else*/
int isBlocked(Game *game, int x, int y) {
    // currently checks only map, no monsters
    Level *level = game->currentLevel;
    Map *map = &level->map;
    if (map->tile[y][x] == TILE_WALL) {
        return 1;
    }
    return 0;
}

void movePlayer(Game *game, MoveDirection dir)
{
    int newx = game->player.pos.x;
    int newy = game->player.pos.y;
    switch (dir) {
        case DIR_UP:
            --newy;
            break;
        case DIR_DOWN:
            ++newy;
            break;
        case DIR_LEFT:
            --newx;
            break;
        case DIR_RIGHT:
            ++newx;
            break;
    }
    if (!isBlocked(game, newx, newy)) {
        game->player.pos.x = newx;
        game->player.pos.y = newy;
    }
}
