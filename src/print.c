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

void printLevel(Level *level)
{
    Map *map = &level->map;
    unsigned int rowOffset = 2;
    mvprintw(0, 2, "Level: %s", level->name);
    // print the whole of map background
    for (unsigned int i = 0; i < map->mapHeight; ++i) {
        for (unsigned int j = 0; j < map->mapWidth; ++j) {
            char c = mapChar(level, j, i);
            mvaddch(i+rowOffset, j, c);
        }
    }
}

void printVisuals(Game *game)
{
    Level *curLevel = game->currentLevel;
    if (game->opts.showAll) {
        printLevel(curLevel);
    }
    refresh();
}
