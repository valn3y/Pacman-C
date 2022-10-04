#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "ui.h"

char printWall[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char printGhost[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char printUser[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char printPill[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char printEmpty[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void printPart(char drawing[4][7], int part) {
	printf("%s", drawing[part]);
}

void printMap(MAP* m) {
	for(int i = 0; i < m->lines; i++) {
		for(int part = 0; part < 4; part++) {
			for(int j = 0; j < m->columns; j++) {
				switch(m->matrix[i][j]) {
					case GHOST:
						printPart(printGhost, part);
						break;

					case USER:
						printPart(printUser, part);
						break;

					case PILL:
						printPart(printPill, part);
						break;

					case WALL_VERTICAL:
					case WALL_HORIZONTAL:
						printPart(printWall, part);
						break;

					case EMPTY:
						printPart(printEmpty, part);
						break;
				}
			}
			printf("\n");
		}
	}
}