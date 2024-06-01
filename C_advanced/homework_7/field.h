#include <stdlib.h>
#include <time.h>

#define MAX_X 26
#define MAX_Y 17

typedef struct pumpkin_t{
	int pumpkin_x;
	int pumpkin_y;
	int pumpkin_state;// 0 - not ripe, 1 - ripe
	char pumpkin_symbol;
} pumpkin_t;

int initField(pumpkin_t pumpkinArray[MAX_X][MAX_Y]);

void pumpkinIsRipe(pumpkin_t pumpkinArray[MAX_X][MAX_Y]);

void pumpkinIsRipe_manual(pumpkin_t pumpkinArray[MAX_X][MAX_Y], int x, int y);