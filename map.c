#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void copyMap(MAP* destiny, MAP* origin) {
	destiny->lines = origin->lines;
	destiny->columns = origin->columns;

	allocMemoryMap(destiny);
	for(int i = 0; i < origin->lines; i++) {
		strcpy(destiny->matrix[i], origin->matrix[i]);
	}
}

void walkingOnTheMap(MAP* m, int xOrigin, int yOrigin, int xDestiny, int yDestiny) {
	char character = m->matrix[xOrigin][yOrigin];
	m->matrix[xDestiny][yDestiny] = character;
	m->matrix[xOrigin][yOrigin] = EMPTY;
}

int isLimit(MAP* m, int x, int y) {
	if(x >= m->lines) {
		return 0;
	}
	if(y >= m->columns){
		return 0;
	}

	return 1;
}

int positionIsEmpty(MAP* m, int x, int y) {
	return m->matrix[x][y] == EMPTY;
}

void findInMap(MAP* m, POSITION* p, char c) {
	for(int i = 0; i < m->lines; i++) {
		for(int j = 0; j < m->columns; j++) {
			if(m->matrix[i][j] == c) {
				p->x = i;
				p->y = j;
				break;
			}
		}
	}
}

void allocMemoryMap(MAP* m) {
	m->matrix = malloc(sizeof(char*) * m->lines);
	for(int i = 0; i < m->lines; i++) {
		m->matrix[i] = malloc(sizeof(char*) * (m->columns + 1));
	}
}

void freeMemoryMap(MAP* m) {
	for(int i = 0; i < m->lines; i++) {
		free(m->matrix[i]);
	}
	free(m->matrix);
}

void readMap(MAP* m) {
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->lines), &(m->columns));

	allocMemoryMap(m);

	for(int i = 0; i < 5; i++) {
		// FULL LINE
		fscanf(f, "%s", m->matrix[i]);
	}
	fclose(f);
}

void printMap(MAP* m) {
	for(int i = 0; i < m->lines; i++) {
		printf("%s\n", m->matrix[i]);
	}
}