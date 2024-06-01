#include <stdio.h>
#include <stdlib.h>

#define MAX_CARTS 8

typedef struct cart_t{
	int x;
	int y;
} cart_t;

typedef struct drone_t{
	int x;
	int y;
	struct cart_t * carts;
	size_t carts_number;
    int direction; //1 - left, 2 - up, 3 - right, 4 - down
	int speed;
}  drone_t;



struct drone_t initDrone(int x, int y);

void turnDrone(drone_t *drone, char key);

void addCart(drone_t *drone);

int selfCrashCheck(drone_t drone);