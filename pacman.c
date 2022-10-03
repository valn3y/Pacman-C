#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION user;

int finishGame() {
	return 0;
}

void move(char direction) {
	int x;
	int y;

	m.matrix[user.x][user.y] = '.';

	switch(direction) {
		case 'a':
			m.matrix[user.x][user.y-1] = '@';
			user.y--;
			break;
		case 'w':
			m.matrix[user.x-1][user.y] = '@';
			user.x--;
			break;
		case 's':
			m.matrix[user.x+1][user.y] = '@';
			user.x++;
			break;
		case 'd':
			m.matrix[user.x][user.y+1] = '@';
			user.y++;
			break;
	}
}

int main() {	
	readMap(&m);
	findInMap(&m, &user, '@');

	do {
		printMap(&m);

		char command;
		scanf(" %c", &command);
		move(command);
	} while(!finishGame());

	freeMemoryMap(&m);
}