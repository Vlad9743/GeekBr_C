#include <stdio.h>

#include "drone.h"
#include "field.h"

typedef struct target_t{
	int x;
	int y;
} target_t;

void printPumpkinField(drone_t droneArray[], int droneNumber, pumpkin_t pumpkinArray[MAX_X][MAX_Y]);

drone_t moveDrone(drone_t drone);

target_t findClosestPumpkin(drone_t drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y]);

target_t findClosestPumpkin_in_zone(drone_t drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y], int min_y, int max_y);

void autoPilot_simple(drone_t *drone, target_t target);// fast, but destroies unripe punpkins on its way

void autoPilot_no_casulties(drone_t *drone, target_t target, pumpkin_t pumpkinArray[MAX_X][MAX_Y]);

void autoPilot_no_casulties_with_zone(drone_t *drone, target_t target, pumpkin_t pumpkinArray[MAX_X][MAX_Y], int min_y, int max_y);

int pumpkinIsGathered(drone_t *drone, pumpkin_t pumpkinArray[MAX_X][MAX_Y]);