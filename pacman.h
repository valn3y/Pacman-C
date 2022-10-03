void freeMemoryMap();
void readMap();
void allocMemoryMap();
int finishGame();
void move(char direction);
void printMap();

struct map {
	char** matrix;
	int lines;
	int columns;
};

typedef struct map MAPA;