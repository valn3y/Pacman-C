#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

int finishGame();
void move(char direction);
int isDirection(char direction);
void ghosts();
int whereGhostGo(int xOrigin, int yOrigin, int* xDestiny, int* yDestiny);