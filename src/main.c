#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "game.h"
#include "mapgen.h"

void initGame(Game *game, int arc, char **argv)
{
    // set opt
    // parse args, e.g. load a game
    Options *opt = &game->opts;
    opt->showAll = 1;
    int loadSave = 0;

    if (!loadSave) {
        generateLevels(game);
        //createPlayer(game);
    }

}

int main(int arc, char **argv)
{
    Game *game = malloc(sizeof(Game));
    assert(game);

    initGame(game, arc, argv);

    int gameOn = 1;

    while(gameOn) {
        // show map etc
        printVisuals(game);
        //char input;
        // read input from stdin
        //gameOn = processInput(game, input);
        Level *curLevel = game->levels[0];
        printf("%s\n", curLevel->name);
        gameOn = 0;
    }

    // free allocated memory objs etc
    freeAll(game);
    free(game);
    return(0);
}
