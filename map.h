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
void printMap(MAP* m);
void findInMap(MAP* m, POSITION* p, char c);