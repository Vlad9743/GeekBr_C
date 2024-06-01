#include "navigation.h"

//отрисовка поля с тыквами и дронами
void printPumpkinField(drone_t droneArray[], int droneNumber, pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	char matrix[MAX_X][MAX_Y];// массив клеток поля

    //копирует в массив поля символы тыкв
	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			matrix[i][j] = pumpkinArray[i][j].pumpkin_symbol;
		}
	}

    //копирует в массив поля символы дронов и тележек
	for (int d = 0; d < droneNumber; d++)
	{
		matrix[droneArray[d].x][droneArray[d].y] = '#';
		for (int i = 0; i < droneArray[d].carts_number; ++i)
		{
	    	matrix[droneArray[d].carts[i].x][droneArray[d].carts[i].y] = '*';
		}
	}

    //выводит в консоль массив поля в соответствии с принятой цветовой маркировкой
    //зеленый - незрелая тыква, красный - зрелая тыква, синий - дрон или тележка
	for (int j = 0; j < MAX_Y; ++j){
		for (int i = 0; i < MAX_X; ++i)
		{
			if (matrix[i][j] == ' ')
			{
				printf("%c", matrix[i][j]);
			}
			else if (matrix[i][j] == '#' || matrix[i][j] == '*')
			{
				printf("\033[0;34m"); //set blue color
				printf("%c", matrix[i][j]);
				printf("\033[0m");//reset color
			}
			else if (matrix[i][j] == 'o')
			{
				if (pumpkinArray[i][j].pumpkin_state == 0)
				{
					printf("\033[0;32m");//set green color
				}
				else if (pumpkinArray[i][j].pumpkin_state == 1)
				{
					printf("\033[0;31m");//set red color
				}	
				printf("%c", matrix[i][j]);
				printf("\033[0m");//reset color
			}
		}
		printf("\n");
	}
}

//переместит дрон на одну клетку в текущем направлении
drone_t moveDrone(drone_t drone)
{
    int stepX = 0;
    int stepY = 0;

    switch (drone.direction)
    {
    case 1://left
        stepX = 1;
        stepY = 0;
        break;

    case 2://up
        stepX = 0;
        stepY = 1;
        break;

    case 3://right
        stepX = -1;
        stepY = 0;
        break;
    
    case 4://down
        stepX = 0;
        stepY = -1;
        break;
    }

    //перемещение хвоста
    for (int i = drone.carts_number - 1; i > 0; i--)
    {
		drone.carts[i] = drone.carts[i-1];
	}
	drone.carts[0].x = drone.x;
	drone.carts[0].y = drone.y;
	
    //премещение головы по вертикали
	drone.y = drone.y - stepY;
	//зацикливание дрона при достижении верхней и нижней границ поля
	if (drone.y < 0)
    {
		drone.y = MAX_Y - 1;
	}
	else if (drone.y > MAX_Y)
	{
		drone.y = 1;
	}

    //перемещение головы по горизонтали
    drone.x = drone.x - stepX;
	//зацикливание дрона при достижении левой и правой границ поля
	if (drone.x < 0){
		drone.x = MAX_X - 1;
	}
	else if (drone.x > MAX_X)
	{
		drone.x = 1;
	}

	return drone;
}

// находит ближайшую к дрону спелую тыкву на поле
target_t findClosestPumpkin(drone_t drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	int distance_X;
	int distance_Y;

	target_t target;

	int min_distance = MAX_X + MAX_Y;

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			if ((pumpkinArray[i][j].pumpkin_symbol == 'o') && (pumpkinArray[i][j].pumpkin_state == 1))
			{
				distance_X = abs(drone.x - pumpkinArray[i][j].pumpkin_x);
				distance_Y = abs(drone.y - pumpkinArray[i][j].pumpkin_y);

				if (min_distance > (distance_X + distance_Y))
				{
					min_distance = (distance_X + distance_Y);
					target.x = pumpkinArray[i][j].pumpkin_x;
					target.y = pumpkinArray[i][j].pumpkin_y;
				}
			}
		}
	}
	return target;
}

//находит ближайшую к дрону спелую тыкву взаданной области
target_t findClosestPumpkin_in_zone(drone_t drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y], int min_y, int max_y)
{
	int distance_X;
	int distance_Y;

	target_t target;
	target.x = MAX_X;
	target.y = min_y;

	int min_distance = MAX_X + (max_y - min_y);

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = min_y; j < max_y; j++)
		{
			if ((pumpkinArray[i][j].pumpkin_symbol == 'o') && (pumpkinArray[i][j].pumpkin_state == 1))
			{
				distance_X = abs(drone.x - pumpkinArray[i][j].pumpkin_x);
				distance_Y = abs(drone.y - pumpkinArray[i][j].pumpkin_y);

				if (min_distance > (distance_X + distance_Y))
				{
					min_distance = (distance_X + distance_Y);
					target.x = pumpkinArray[i][j].pumpkin_x;
					target.y = pumpkinArray[i][j].pumpkin_y;
				}
			}
		}
	}
	return target;
}

//ведет дрон к объекту target кратчайшим образом. Допускает наезд на незрелые тыквы.
void autoPilot_simple(drone_t *drone, target_t target)
{
	if (((drone->direction) == 1) || ((drone->direction) == 3))
	{
		if (target.y > (drone->y))
		{
			(drone->direction) = 4;
		}
		else if (target.y < (drone->y))
		{
			(drone->direction) = 2;
		}
	}
	else if (((drone->direction) == 2) || ((drone->direction) == 4))
	{
		if (target.x > (drone->x))
		{
			(drone->direction) = 3;
		}
		else if (target.x < (drone->x))
		{
			(drone->direction) = 1;
		}
	}
}

//движется к объекту target, объезжая незрелые тыквы
void autoPilot_no_casulties(drone_t *drone, target_t target, pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	if (((drone->direction) == 1))
	{
		if (pumpkinArray[drone->x - 1][drone->y].pumpkin_symbol == 'o' && pumpkinArray[drone->x - 1][drone->y].pumpkin_state != 1)
		{
			if (target.y > (drone->y))
			{
				(drone->direction) = 4;
			}
			else 
			{
				(drone->direction) = 2;
			}
		}
		else
		{
			if (target.y > (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y+1].pumpkin_state == 1)
				{
					drone->direction = 4;
				}
			}
			if (target.y < (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y-1].pumpkin_state == 1)
				{
					drone->direction = 2;
				}
			}
		}
	}
//---------------------------------------------
	else if (((drone->direction) == 3))
	{
		if (pumpkinArray[drone->x + 1][drone->y].pumpkin_symbol == 'o' && pumpkinArray[drone->x + 1][drone->y].pumpkin_state != 1)
		{
			if (target.y > (drone->y))
			{
				(drone->direction) = 4;
			}
			else 
			{
				(drone->direction) = 2;
			}
		}
		else
		{
			if (target.y > (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y+1].pumpkin_state == 1)
				{
					drone->direction = 4;
				}
			}
			if (target.y < (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y-1].pumpkin_state == 1)
				{
					drone->direction = 2;
				}
			}
		}
	}
//---------------------------------------------
	else if (((drone->direction) == 2))
	{
		if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol == 'o' && pumpkinArray[drone->x][drone->y-1].pumpkin_state != 1)
		{
			if (target.x > (drone->x))
			{
				(drone->direction) = 3;
			}
			else 
			{
				(drone->direction) = 1;
			}
		}
		else
		{
			if (target.x > (drone->x))
			{
				if (pumpkinArray[drone->x+1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x+1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 3;
				}
			}
			if (target.x < (drone->x))
			{
				if (pumpkinArray[drone->x-1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x-1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 1;
				}
			}
		}
	}
//---------------------------------------------
	else if (((drone->direction) == 4))
	{
		if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol == 'o' && pumpkinArray[drone->x][drone->y+1].pumpkin_state != 1)
		{
			if (target.x > (drone->x))
			{
				(drone->direction) = 3;
			}
			else 
			{
				(drone->direction) = 1;
			}
		}
		else
		{
			if (target.x > (drone->x))
			{
				if (pumpkinArray[drone->x+1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x+1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 3;
				}
			}
			if (target.x < (drone->x))
			{
				if (pumpkinArray[drone->x-1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x-1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 1;
				}
			}
		}
	}
}

//движется к объекту target, объезжая незрелые тыквы. Зона действия ограничена координатами min_y и max_y
void autoPilot_no_casulties_with_zone(drone_t *drone, target_t target, pumpkin_t pumpkinArray[MAX_X][MAX_Y], int min_y, int max_y)
{
	if (((drone->direction) == 1))
	{
		if (pumpkinArray[drone->x - 1][drone->y].pumpkin_symbol == 'o' && pumpkinArray[drone->x - 1][drone->y].pumpkin_state != 1)
		{
			if (target.y > (drone->y))
			{
				(drone->direction) = 4;
			}
			else 
			{
				(drone->direction) = 2;
			}
		}
		else
		{
			if (target.y > (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y+1].pumpkin_state == 1)
				{
					drone->direction = 4;
				}
			}
			if (target.y < (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y-1].pumpkin_state == 1)
				{
					drone->direction = 2;
				}
			}
		}
	}
//---------------------------------------------
	else if (((drone->direction) == 3))
	{
		if (pumpkinArray[drone->x + 1][drone->y].pumpkin_symbol == 'o' && pumpkinArray[drone->x + 1][drone->y].pumpkin_state != 1)
		{
			if (target.y > (drone->y))
			{
				(drone->direction) = 4;
			}
			else 
			{
				(drone->direction) = 2;
			}
		}
		else
		{
			if (target.y > (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y+1].pumpkin_state == 1)
				{
					drone->direction = 4;
				}
			}
			if (target.y < (drone->y))
			{
				if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol != 'o' || pumpkinArray[drone->x][drone->y-1].pumpkin_state == 1)
				{
					drone->direction = 2;
				}
			}
		}
	}
//---------------------------------------------UP
	else if (((drone->direction) == 2))
	{
		if (drone->y == min_y) drone->direction = 1;
		if (pumpkinArray[drone->x][drone->y-1].pumpkin_symbol == 'o' && pumpkinArray[drone->x][drone->y-1].pumpkin_state != 1)
		{
			if (target.x > (drone->x))
			{
				(drone->direction) = 3;
			}
			else 
			{
				(drone->direction) = 1;
			}
		}
		else
		{
			if (target.x > (drone->x))
			{
				if (pumpkinArray[drone->x+1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x+1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 3;
				}
			}
			if (target.x < (drone->x))
			{
				if (pumpkinArray[drone->x-1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x-1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 1;
				}
			}
		}
	}
//---------------------------------------------DOWN
	else if (((drone->direction) == 4))
	{	
		if (drone->y == max_y) drone->direction = 1;
		if (pumpkinArray[drone->x][drone->y+1].pumpkin_symbol == 'o' && pumpkinArray[drone->x][drone->y+1].pumpkin_state != 1)
		{
			if (target.x > (drone->x))
			{
				(drone->direction) = 3;
			}
			else 
			{
				(drone->direction) = 1;
			}
		}
		else
		{
			if (target.x > (drone->x))
			{
				if (pumpkinArray[drone->x+1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x+1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 3;
				}
			}
			if (target.x < (drone->x))
			{
				if (pumpkinArray[drone->x-1][drone->y].pumpkin_symbol != 'o' || pumpkinArray[drone->x-1][drone->y].pumpkin_state == 1)
				{
					drone->direction = 1;
				}
			}
		}
	}
}

// реакция дрона на объекты на поле
int pumpkinIsGathered(drone_t *drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y])
{
	int flag = 0;// 0 - нет события, 1 - тыква собрана, 2 - тыква уничтожена

	if (pumpkinArray[drone->x][drone->y].pumpkin_symbol == 'o')
	{
		pumpkinArray[drone->x][drone->y].pumpkin_symbol = ' ';

		if (pumpkinArray[drone->x][drone->y].pumpkin_state == 1 && drone->carts_number < MAX_CARTS)
		{
			flag = 1;
			addCart(drone);
		}
		else
		{
			flag = 2;
		}
	}

	return flag;
}