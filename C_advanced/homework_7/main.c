#include "navigation.h"
#include "aux_func.h"

int main(void)
{
	int droneNumber = 3; //количество дронов на поле

	int drone_start_x = MAX_X - 1; // стартовые позиции дронов
	int drone_start_y = 1;

	int drone1_start_x = MAX_X - 1 ;
	int drone1_start_y = MAX_Y / 2;

	int drone2_start_x = MAX_X - 1;
	int drone2_start_y = MAX_Y-3;

    int droneCrashed = 0;//флаг, показывающий, что дрон врезался в тележки
	int pumpkinsGathered = 0;//счетчик собранных зрелых тыкв
	int pumpkinsDestroied = 0;//счетчик уничтоженных незрелых тыкв

	char dir_key = 'a';//переменная для считывания клавиш управления при ручном контроле дрона

	drone_t droneArray[droneNumber];//массив дронов
	droneArray[0] = initDrone(drone_start_x, drone_start_y);
	droneArray[1] = initDrone(drone1_start_x, drone1_start_y);
	droneArray[2] = initDrone(drone2_start_x, drone2_start_y);

	pumpkin_t pumpkinArray[MAX_X][MAX_Y];//массив тыкв
	int pumpkinsTotal = initField(pumpkinArray);//общее количество тыкв на поле
	printPumpkinField(droneArray, droneNumber, pumpkinArray);

	struct timespec drone_delay, drone_delay2;
	drone_delay.tv_sec = 0;
	drone_delay.tv_nsec = 100000000;

	pumpkinIsRipe_manual(pumpkinArray, 10, 5);//добавление зрелых тыкв на начальное поле
	pumpkinIsRipe_manual(pumpkinArray, 20, 5);

	target_t target;//координаты целей дронов
	target_t target1;
	target_t target2;

    //основной цикл продолжается пока не закончатся тыквы или дрон не врежется в тележки
	while(((pumpkinsGathered + pumpkinsDestroied) < pumpkinsTotal) && !droneCrashed)
	{
		if (kbhit())//ручное управление первым дроном. В данном случае не используется. Все дроны на автопилоте.
		{
			dir_key = getch();
			turnDrone(&droneArray[0], dir_key);
		}
		
		target = findClosestPumpkin_in_zone(droneArray[0], pumpkinArray, 1, 6);//поиск ближайшей зрелой тыквы в своей зоне ответственности - первые 6 строк поля
		target1 = findClosestPumpkin_in_zone(droneArray[1], pumpkinArray, 7, 12);
		target2 = findClosestPumpkin_in_zone(droneArray[2], pumpkinArray, 13, 15);
	
		autoPilot_no_casulties_with_zone(&droneArray[0], target, pumpkinArray, 1, 6);//разворот дрона к найденной тыкве. при приближении в границе зоны также происходит поворот
		autoPilot_no_casulties_with_zone(&droneArray[1], target1, pumpkinArray, 7, 12);
		autoPilot_no_casulties_with_zone(&droneArray[2], target2, pumpkinArray, 13, 15);

		droneArray[0] = moveDrone(droneArray[0]);//перемещение дрона на одну клетку
		droneArray[1] = moveDrone(droneArray[1]);
		droneArray[2] = moveDrone(droneArray[2]);

        int pumpkinEvent[droneNumber];//обработка событий взаимодействия дронов и тыкв
		pumpkinEvent[0] = pumpkinIsGathered(&droneArray[0], pumpkinArray);//0 - нет события
		pumpkinEvent[1] = pumpkinIsGathered(&droneArray[1], pumpkinArray);
		pumpkinEvent[2] = pumpkinIsGathered(&droneArray[2], pumpkinArray);
        for (int i = 0; i < droneNumber; i++)
        {
            if (pumpkinEvent[i] == 1) pumpkinsGathered++;//1 - собрана зрелая тыква
            else if (pumpkinEvent[i] == 2) pumpkinsDestroied++;//2 - уничтожене незрелая тыква
        }

		system("clear");
		printPumpkinField(droneArray, droneNumber, pumpkinArray);//отрисовка поля
		printScore(pumpkinsGathered, pumpkinsDestroied);//вывод счетчиков тыкв
		nanosleep(&drone_delay, &drone_delay2);

        for (int i = 0; i < 10; i++)// цикл нужен, что бы увеличить количество созревших тыкв за одну итерацию
        {
		    pumpkinIsRipe(pumpkinArray);//рандомное созревание тыкв
        }

        for (int i = 0; i < droneNumber; i++)//проверка на врезание дронов в тележки
        {
            droneCrashed += selfCrashCheck(droneArray[i]);
        }
	}

	return 0;
}