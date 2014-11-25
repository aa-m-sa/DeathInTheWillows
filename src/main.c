#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>
#include "game.h"
#include "mapgen.h"
#include "print.h"

void initGame(Game *game, int arc, char **argv)
{
    // set opt
    // parse args, e.g. load a game
    Options *opt = &game->opts;
    opt->showAll = 1;
    int loadSave = 0;

    if (!loadSave) {
        generateLevels(game);
        game->currentLevel = game->levels[0];
        //createPlayer(game);
    }

}

int main(int arc, char **argv)
{
    Game *game = malloc(sizeof(Game));
    assert(game);

    initGame(game, arc, argv);
    initCurses();

    int gameOn = 1;
    while(gameOn) {
        // show map etc
        Level *curLevel = game->currentLevel;
        printf("%s\n", curLevel->name);
        printVisuals(game);
        // read input
        char input = getch();
        //gameOn = processInput(game, input);
        gameOn = 0;
    }

    endCurses();

    // free allocated memory objs etc
    freeAll(game);
    free(game);
    return(0);
}
