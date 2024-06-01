#include "navigation.h"
#include "aux_func.h"

int main(void)
{
	int droneNumber = 3;

	int drone_start_x = MAX_X - 1;
	int drone_start_y = 1;

	int drone1_start_x = MAX_X - 1 ;
	int drone1_start_y = MAX_Y / 2;

	int drone2_start_x = MAX_X - 1;
	int drone2_start_y = MAX_Y-3;

    int droneCrashed = 0;
	int pumpkinsGathered = 0;
	int pumpkinsDestroied = 0;

	char dir_key = 'a';

	int temp = 0;

	drone_t droneArray[droneNumber];
	droneArray[0] = initDrone(drone_start_x, drone_start_y);
	droneArray[1] = initDrone(drone1_start_x, drone1_start_y);
	droneArray[2] = initDrone(drone2_start_x, drone2_start_y);

	pumpkin_t pumpkinArray[MAX_X][MAX_Y];
	int pumpkinsTotal = initField(pumpkinArray);
	printPumpkinField(droneArray, droneNumber, pumpkinArray);

	struct timespec drone_delay, drone_delay2;
	drone_delay.tv_sec = 0;
	drone_delay.tv_nsec = 500000000;

	pumpkinIsRipe_manual(pumpkinArray, 10, 5);
	pumpkinIsRipe_manual(pumpkinArray, 20, 5);

	target_t target;
	target_t target1;
	target_t target2;

	while(((pumpkinsGathered + pumpkinsDestroied) < pumpkinsTotal) && !droneCrashed)
	{
		
		if (kbhit())
		{
			dir_key = getch();
			turnDrone(&droneArray[0], dir_key);
		}
		
		target = findClosestPumpkin_in_zone(droneArray[0], pumpkinArray, 1, 6);
		target1 = findClosestPumpkin_in_zone(droneArray[1], pumpkinArray, 7, 12);
		target2 = findClosestPumpkin_in_zone(droneArray[2], pumpkinArray, 13, 15);
	
		autoPilot_no_casulties_with_zone(&droneArray[0], target, pumpkinArray, 1, 6);
		autoPilot_no_casulties_with_zone(&droneArray[1], target1, pumpkinArray, 7, 12);
		autoPilot_no_casulties_with_zone(&droneArray[2], target2, pumpkinArray, 13, 15);

		droneArray[0] = moveDrone(droneArray[0]);
		droneArray[1] = moveDrone(droneArray[1]);
		droneArray[2] = moveDrone(droneArray[2]);

        int pumpkinEvent[droneNumber];
		pumpkinEvent[0] = pumpkinIsGathered(&droneArray[0], pumpkinArray);
		pumpkinEvent[1] = pumpkinIsGathered(&droneArray[1], pumpkinArray);
		pumpkinEvent[2] = pumpkinIsGathered(&droneArray[2], pumpkinArray);
        for (int i = 0; i < droneNumber; i++)
        {
            if (pumpkinEvent[i] == 1) pumpkinsGathered++;
            else if (pumpkinEvent[i] == 2) pumpkinsDestroied++;
        }

		system("clear");
		printPumpkinField(droneArray, droneNumber, pumpkinArray);
		printScore(pumpkinsGathered, pumpkinsDestroied);
		nanosleep(&drone_delay, &drone_delay2);

		pumpkinIsRipe(pumpkinArray);

        for (int i = 0; i < droneNumber; i++)
        {
            droneCrashed += selfCrashCheck(droneArray[i]);
        }
	}

	return 0;
}