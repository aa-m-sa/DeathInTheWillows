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
