#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION user;
int havePill = 0;

int whereGhostGo(int xOrigin, int yOrigin, int* xDestiny, int* yDestiny) {
	int options[4][2] = {
		{xOrigin, yOrigin + 1},
		{xOrigin + 1, yOrigin},
		{xOrigin, yOrigin - 1},
		{xOrigin - 1, yOrigin}
	};

	srand(time(0));
	for(int i = 0; i < 10; i++) {
		int position = rand() % 4;
		if(canWalk(&m, GHOST, options[position][0], options[position][1])) {
			*xDestiny = options[position][0];
			*yDestiny = options[position][1];
			return 1;
		}
	}

	return 0;
}

void ghosts() {
	MAP copy;
	copyMap(&copy, &m);

	for(int i = 0; i < m.lines; i++) {
		for(int j = 0; j < m.columns; j++) {
			if(copy.matrix[i][j] == GHOST) {
				int xDestiny;
				int yDestiny;

				int found = whereGhostGo(i, j, &xDestiny, &yDestiny);

				if(found) {
					walkingOnTheMap(&m, i, j, xDestiny, yDestiny);
				}
			}
		}
	}

	freeMemoryMap(&copy);
}

int finishGame() {
	POSITION pos;
	int foundUser = findInMap(&m, &pos, USER);
	return !foundUser;
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

	if(!canWalk(&m, USER, proxX, proxY)) {
		return;
	}

	if(isCharacter(&m, PILL, proxX, proxY)) {
		havePill = 1;
	}

	walkingOnTheMap(&m, user.x, user.y, proxX, proxY);
	user.x = proxX;
	user.y = proxY;	
}

void explodesPill() {
	if(!havePill) {
		return;
	}

	explodesPill2(user.x, user.y, 0, 1, 3);
	explodesPill2(user.x, user.y, 0, -1, 3);
	explodesPill2(user.x, user.y, 1, 0, 3);
	explodesPill2(user.x, user.y, -0, 0, 3);

	havePill = 0;
}

void explodesPill2(int x, int y, int sumX, int sumY, int quantity) {
	if(quantity == 0) {
		return;
	}

	int newX = x + sumX;
	int newY = y + sumY;

	if(!isLimit(&m, newX, newY)) {
		return;
	}
	if(isWall(&m, newX, newY)) {
		return;
	}

	m.matrix[newX][newY] = EMPTY;
	explodesPill2(newX, newY, sumX, sumY, quantity - 1);
}

int main() {	
	readMap(&m);
	findInMap(&m, &user, USER);

	do {
		printf("Tem pilula: %s\n", (havePill ? "SIM" : "NAO"));
		printMap(&m);

		char command;
		scanf(" %c", &command);

		move(command);

		if(command == BOMB) {
			explodesPill();
		}

		ghosts();
	} while(!finishGame());

	freeMemoryMap(&m);
}