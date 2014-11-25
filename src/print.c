/* visual output implementation*/
#include <stdio.h>
#include <ncurses.h>
#include "print.h"

void initCurses()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    // cursor normally invisible
    curs_set(0);
}

void endCurses()
{
    endwin();
}

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

void printCurLevel(Game *game)
{
    Level *level = game->currentLevel;
    Map *map = &level->map;

    // where the map is printed on screen
    unsigned int rowOffset = 2;

    // print level name above the map
    mvprintw(0, 2, "Level: %s", level->name);

    // print the whole of map background
    for (unsigned int i = 0; i < map->mapHeight; ++i) {
        for (unsigned int j = 0; j < map->mapWidth; ++j) {
            char c = mapChar(level, j, i);
            mvaddch(i+rowOffset, j, c);
        }
    }

    // print the player
    // to be replaced with "printPlayer" or a more general "printCreature" fun
    int px = game->player.pos.x;
    int py = game->player.pos.y;
    char pchar = game->player.sign;
    mvaddch(py + rowOffset, px, pchar);
}

void printVisuals(Game *game)
{
    if (game->opts.showAll) {
        printCurLevel(game);
    }
    refresh();
}
