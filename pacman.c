#include <stdio.h>
#include <stdlib.h>

char** map;
int lines;
int columns;

void allocMemoryMap() {
	map = malloc(sizeof(char*) * lines);
	for(int i = 0; i < lines; i++) {
		map[i] = malloc(sizeof(char*) * (columns + 1));
	}
}

void freeMemoryMap() {
	for(int i = 0; i < lines; i++) {
		free(map[i]);
	}
	free(map);
}

void readMap() {
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	fscanf(f, "%d %d", &lines, &columns);

	allocMemoryMap();

	for(int i = 0; i < 5; i++) {
		// FULL LINE
		fscanf(f, "%s", map[i]);
	}
	fclose(f);
}

int main() {	
	readMap();

	for(int i = 0; i < 5; i++) {
		printf("%s\n", map[i]);
	}

	freeMemoryMap();
}