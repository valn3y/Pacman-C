#include <stdio.h>
#include <stdlib.h>

char map[200][200+1];
int lines;
int columns;

int main() {
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	for(int i = 0; i < 5; i++) {
		// FULL LINE
		fscanf(f, "%s", map[i]);
	}

	for(int i = 0; i < 5; i++) {
		printf("%s\n", map[i]);
	}

	fclose(f);
}