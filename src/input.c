/* user input handling*/
#include "input.h"
#include "game.h"
#include "player.h"

int processInput(Game *game, char input)
{
    int command = 1;
    switch (input) {
        case 'q':
            command = 0;
            break;
        case 'k':
            movePlayer(game, DIR_UP);
            break;
        case 'j':
            movePlayer(game, DIR_DOWN);
            break;
        case 'h':
            movePlayer(game, DIR_LEFT);
            break;
        case 'l':
            movePlayer(game, DIR_RIGHT);
            break;
    }
    return command;
}
