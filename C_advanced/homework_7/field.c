#include "field.h"

int initField(pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	int pumpkinsTotal = 0;

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			pumpkinArray[i][j].pumpkin_state = 0;
			pumpkinArray[i][j].pumpkin_symbol = ' ';
			pumpkinArray[i][j].pumpkin_x = i;
			pumpkinArray[i][j].pumpkin_y = j;
		}
	}

	for (int j = 2; j < MAX_Y; j += 3)
	{
		for (int i = 2; i < MAX_X; i += 6)
		{
			pumpkinArray[i][j].pumpkin_symbol = 'o';
			pumpkinArray[i + 1][j].pumpkin_symbol = 'o';
			pumpkinArray[i + 2][j].pumpkin_symbol = 'o';
			pumpkinArray[i + 3][j].pumpkin_symbol = 'o';
			pumpkinsTotal += 4;
		}
	}
	return pumpkinsTotal;
}

void pumpkinIsRipe(pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	time_t t;
	srand((unsigned) time(&t));

	int newX = rand() % (MAX_X - 1) + 1;
	int newY = rand() % (MAX_Y - 1) + 1;

	if (pumpkinArray[newX][newY].pumpkin_symbol == 'o' && pumpkinArray[newX][newY].pumpkin_state == 0)
	{
		pumpkinArray[newX][newY].pumpkin_state = 1;
	}
}

void pumpkinIsRipe_manual(pumpkin_t pumpkinArray[MAX_X][MAX_Y], int x, int y)
{
	pumpkinArray[x][y].pumpkin_state = 1;
}