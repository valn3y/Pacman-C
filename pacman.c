#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION user;


void ghosts() {
	MAP copy;
	copyMap(&copy, &m);

	for(int i = 0; i < m.lines; i++) {
		for(int j = 0; j < m.columns; j++) {
			if(copy.matrix[i][j] == GHOST) {
				if(isLimit(&m, i, j+1) && positionIsEmpty(&m, i, j+1)) {
					walkingOnTheMap(&m, i, j, i, j+1);
				}
			}
		}
	}

	freeMemoryMap(&copy);
}

int finishGame() {
	return 0;
}

int isDirection(char direction) {
	return direction == LEFT || direction == UP || direction == DOWN || direction == RIGHT;
}

void move(char direction) {
	if(!isDirection(direction)) {
		return;
	}

	int proxX = user.x;
	int proxY = user.y;

	switch(direction) {
		case LEFT:
			proxY--;
			break;
		case UP:
			proxX--;
			break;
		case DOWN:
			proxX++;
			break;
		case RIGHT:
			proxY++;
			break;
	}

	if(!isLimit(&m, proxX, proxY)) {
		return;
	}

	if(!positionIsEmpty(&m, proxX, proxY)) {
		return;
	} 

	walkingOnTheMap(&m, user.x, user.y, proxX, proxY);
	user.x = proxX;
	user.y = proxY;	
}

int main() {	
	readMap(&m);
	findInMap(&m, &user, USER);

	do {
		printMap(&m);

		char command;
		scanf(" %c", &command);
		move(command);
		ghosts();
	} while(!finishGame());

	freeMemoryMap(&m);
}