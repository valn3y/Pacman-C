#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

MAPA m;

void allocMemoryMap() {
	m.matrix = malloc(sizeof(char*) * m.lines);
	for(int i = 0; i < m.lines; i++) {
		m.matrix[i] = malloc(sizeof(char*) * (m.columns + 1));
	}
}

void freeMemoryMap() {
	for(int i = 0; i < m.lines; i++) {
		free(m.matrix[i]);
	}
	free(m.matrix);
}

void readMap() {
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(m.lines), &(m.columns));

	allocMemoryMap();

	for(int i = 0; i < 5; i++) {
		// FULL LINE
		fscanf(f, "%s", m.matrix[i]);
	}
	fclose(f);
}

int finishGame() {
	return 0;
}

void move(char direction) {
	int x;
	int y;

	for(int i = 0; i < m.lines; i++) {
		for(int j = 0; j < m.columns; j++) {
			if(m.matrix[i][j] == '@') {
				x = i;
				y = j;
				break;
			}
		}
	}

	switch(direction) {
		case 'a':
			m.matrix[x][y-1] = '@';
			break;
		case 'w':
			m.matrix[x-1][y] = '@';
			break;
		case 's':
			m.matrix[x+1][y] = '@';
			break;
		case 'd':
			m.matrix[x][y+1] = '@';
			break;
	}

	m.matrix[x][y] = '.';
}

void printMap() {
	for(int i = 0; i < m.lines; i++) {
		printf("%s\n", m.matrix[i]);
	}
}

int main() {	
	readMap();

	do {
		printMap();

		char command;
		scanf(" %c", &command);
		move(command);
	} while(!finishGame());

	freeMemoryMap();
}