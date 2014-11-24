#ifndef GAME_H
#define GAME_H

/* definitions for game objects */

// coordinate representation
typedef struct {
    int x, y;
} Point;

// Different tile types
typedef enum {
    TILE_OPEN,
    TILE_WALL,
    TILE_ROOM
} Tile;


// a two dimensional map object (each map for levels)
// allocated dynamically
typedef struct {
    Tile **tile;    // tile[y][x]
    unsigned int mapHeight;
    unsigned int mapWidth;
} Map;

struct level_st;
struct creature_st;

// represents creatures in the game
typedef struct creature_st {
    char name[20];
    char sign;
    Point pos;
    float hp;
    unsigned int maxhp;
    void (*move)(struct level_st *, struct creature_st *);  // current movement algorithm for monster
    void (*attack)(struct level_st *, struct creature_st *);  // current attack algorithm for monster
} Creature;

// level object, contains map and monsters
// currently only one level
typedef struct level_st {
    char name[20];
    unsigned int numMonsters;
    Creature *monsters;
    Map map;
} Level;

// global game options
typedef struct {
    int showAll;    // for debugging, if 1, show the whole map
} Options;

typedef struct game_st {
    unsigned int numLevels;
    Level *levels;
    Creature player;
    Options opts;
} Game;

#endif // GAME_H

