#ifndef _MAP_H_
#define _MAP_H_

#define USER '@'
#define GHOST '$'
#define PILL 'P'
#define EMPTY '.'
#define WALL_VERTICAL '|'
#define WALL_HORIZONTAL '-'

struct map {
	char** matrix;
	int lines;
	int columns;
};

typedef struct map MAP;

struct position {
	int x;
	int y;
};

typedef struct position POSITION;

void freeMemoryMap(MAP* m);
void readMap(MAP* m);
void allocMemoryMap(MAP* m);
int findInMap(MAP* m, POSITION* p, char c);
int isLimit(MAP* m, int x, int y);
int positionIsEmpty(MAP* m, int x, int y);
void walkingOnTheMap(MAP* m, int xOrigin, int yOrigin, int xDestiny, int yDestiny);
void copyMap(MAP* destiny, MAP* origin);
int canWalk(MAP* m, char character, int x, int y);
int isCharacter(MAP* m, char character, int x, int y);
int isWall(MAP* m, int x, int y);

#endif