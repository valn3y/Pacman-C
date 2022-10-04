#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define BOMB 'b'

int finishGame();
void move(char direction);
int isDirection(char direction);
void ghosts();
int whereGhostGo(int xOrigin, int yOrigin, int* xDestiny, int* yDestiny);
void explodesPill();
void explodesPill2(int x, int y, int sumX, int sumY, int quantity);