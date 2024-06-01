#include "drone.h"

// функция для создания объекта дрона
struct drone_t initDrone(int x, int y){
	drone_t drone;
    drone.direction = 1;
	drone.x = x;
	drone.y = y;
	drone.carts_number = 0;
	drone.carts = (cart_t *) malloc (sizeof(cart_t) * MAX_CARTS);
	return drone;
}

// ручное управление дроном
void turnDrone(drone_t *drone, char key)
{
	if ((key == 'a' || key == 'A') && (drone->direction != 3))
    {
        drone->direction = 1;
    }
    else if ((key == 'w' || key == 'W') && (drone->direction != 4))
    {
        drone->direction = 2;
    }
    else if ((key == 'd' || key == 'D') && (drone->direction != 1))
    {
        drone->direction = 3;
    }
    else if ((key == 's' || key == 'S') && (drone->direction != 2))
    {
        drone->direction = 4;
    }
}

//добавит тележку к хвосту дрона
void addCart(drone_t *drone)
{
	drone->carts_number++;

	for (int i = drone->carts_number - 1; i > 0; i--)
	{
		drone->carts[i].x == drone->carts[i - 1].x;
		drone->carts[i].y == drone->carts[i - 1].y;
	}

	drone->carts[0].x == drone->x;
	drone->carts[0].y == drone->y;
}

//проверка на пересечение дрона с хвостом тележек
int selfCrashCheck(drone_t drone)
{
	int crash = 0;
	int i = 0;
	while (!crash && i < drone.carts_number)
	{
		if (drone.x == drone.carts[i].x)
		{
			if (drone.y == drone.carts[i].y)
			{
				crash = 1;
				printf("!!! Allert: Drone crashed into the cart !!!\n");
			}
		}
		i++;
	}
	return crash;
}