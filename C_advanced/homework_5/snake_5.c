#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <fcntl.h>

#define MAX_X 15
#define MAX_Y 15

typedef struct tail_t{
	int x;
	int y;
} tail_t;
	
typedef struct snake_t{
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
    int direction; //1 - left, 2 - up, 3 - right, 4 - down
	int speed;
}  snake_t;

typedef struct food_t{
	int food_x;
	int food_y;
	char food_symbol;
} food_t;

typedef struct menuTable
{
    int pointer[3];
    char menuLines[3];
}menuTable;

struct snake_t initSnake(int x, int y, size_t tsize){
	struct snake_t snake;
    snake.direction = 1;
	snake.speed = 1;
	snake.x = x;
	snake.y = y;
	snake.tsize = tsize;
	snake.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		snake.tail[i].x = x + i +1;
		snake.tail[i].y = y;
		}
	return snake;
}


//---------------------------------------------------------//

void printSnakeAndFood(struct snake_t snake, struct snake_t snake2, food_t foodArray[], int foodAmount){
	char matrix[MAX_X][MAX_Y];
	for (int i = 0; i < MAX_X; ++i){
		for (int j = 0; j < MAX_Y; ++j)
		{
			matrix[i][j] = ' ';
		}
    }

	for (int i = 0; i < foodAmount; i++)
	{
		matrix[foodArray[i].food_x][foodArray[i].food_y] = foodArray[i].food_symbol;
	}
		
	matrix[snake.x][snake.y] = '@';
	for (int i = 0; i < snake.tsize; ++i){
	    matrix[snake.tail[i].x][snake.tail[i].y] = '*';
	}

	matrix[snake2.x][snake2.y] = '%';
	for (int i = 0; i < snake2.tsize; ++i){
	    matrix[snake2.tail[i].x][snake2.tail[i].y] = '+';
	}	

	for (int j = 0; j < MAX_Y; ++j){
		for (int i = 0; i < MAX_X; ++i)
		{
			if (matrix[i][j] == ' ')
			{
				printf("%c", matrix[i][j]);
			}
			else if (matrix[i][j] == '@' || matrix[i][j] == '*')
			{
				printf("\033[0;32m");//set green color
				printf("%c", matrix[i][j]);
				printf("\033[0m");//reset color
			}
			else if (matrix[i][j] == '%' || matrix[i][j] == '+')
			{
				printf("\033[0;31m");//set red color
				printf("%c", matrix[i][j]);
				printf("\033[0m");//reset color
			}
			else if (matrix[i][j] == '#')
			{
				printf("\033[0;34m"); //set blue color
				printf("%c", matrix[i][j]);
				printf("\033[0m");//reset color
			}
		}
		printf("\n");
	}
}

/////////////////////////////////////////
int getch( ) {
   struct termios oldt,
   newt;
   int ch;
   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   ch = getchar();
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   return ch;
}
/////////////////////////////////////////

int kbhit() {
struct termios oldt, newt;
int ch;
int oldf;

tcgetattr(STDIN_FILENO, &oldt);
newt = oldt;
newt.c_lflag &= ~(ICANON | ECHO);
tcsetattr(STDIN_FILENO, TCSANOW, &newt);
oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

ch = getchar();

tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
fcntl(STDIN_FILENO, F_SETFL, oldf);

if(ch != EOF) {
    ungetc(ch, stdin);
    return 1;
}

return 0;
}

/////////////////////////////////////////

snake_t moveSnake(snake_t snake)
{
    int stepX = 0;
    int stepY = 0;

    switch (snake.direction)
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

    for (int i = snake.tsize - 1; i > 0; i--)
    {
		snake.tail[i] = snake.tail[i-1];
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.y = snake.y - stepY;	
	if (snake.y < 0)
    {
		snake.y = MAX_Y - 1;
	}
	else if (snake.y > MAX_Y)
	{
		snake.y = 1;
	}

    snake.x = snake.x - stepX;	
	if (snake.x < 0){
		snake.x = MAX_X - 1;
	}
	else if (snake.x > MAX_X)
	{
		snake.x = 1;
	}

	return snake;
}

void turnSnake(snake_t *snake, snake_t *snake2, char key)
{
	if ((key == 'a' || key == 'A') && (snake->direction != 3))
    {
        snake->direction = 1;
    }
    else if ((key == 'w' || key == 'W') && (snake->direction != 4))
    {
        snake->direction = 2;
    }
    else if ((key == 'd' || key == 'D') && (snake->direction != 1))
    {
        snake->direction = 3;
    }
    else if ((key == 's' || key == 'S') && (snake->direction != 2))
    {
        snake->direction = 4;
    }
	//-----------------------------------------------------------//
	if ((key == 'j' || key == 'J') && (snake2->direction != 3))
    {
        snake2->direction = 1;
    }
    else if ((key == 'i' || key == 'I') && (snake2->direction != 4))
    {
        snake2->direction = 2;
    }
    else if ((key == 'l' || key == 'L') && (snake2->direction != 1))
    {
        snake2->direction = 3;
    }
    else if ((key == 'k' || key == 'K') && (snake2->direction != 2))
    {
        snake2->direction = 4;
    }
}

void initFood(food_t foodArray[], int foodAmount, int snake_line)
{
	time_t t;
	srand((unsigned) time(&t));

	for (int i = 0; i < foodAmount; i++)
	{
		
		foodArray[i].food_x = rand() % (MAX_X - 1) + 1;
		foodArray[i].food_y = rand() % (MAX_Y - 1) + 1;
		if (foodArray[i].food_y == snake_line)
		{
			foodArray[i].food_y += 2;//что бы еда не появилась на змейке
		}
		foodArray[i].food_symbol = '#';
	}
}

int foodIsEaten(snake_t *snake, snake_t *snake2,food_t foodArray[], int foodAmount)
{
	int flag = 0;
	for (int i = 0; i < foodAmount; i++)
	{
		if (snake->x == foodArray[i].food_x || snake2->x == foodArray[i].food_x)
		{
			if (snake->y == foodArray[i].food_y || snake2->y == foodArray[i].food_y)
			{
				if (foodArray[i].food_symbol == '#')
				{
					foodArray[i].food_symbol = ' ';
					flag = 1;
					snake->speed += 1;
				}
			}
		}
	}
	return flag;
}

void autoSnake(snake_t *snake, food_t foodArray[], int foodAmount)
{

	int min_dist = MAX_X + MAX_Y;
	int closest_food_num = 0;
	int temp = 0;
	for (int i = 0; i < foodAmount; i++)
	{
		if (foodArray[i].food_symbol == '#')
		{
			temp = abs((snake->x) - foodArray[i].food_x) + abs((snake->y) - foodArray[i].food_y);
			if (temp < min_dist)
			{
				min_dist = temp;
				closest_food_num = i;
			}
		}
	}

	if (snake->direction == 1 || snake->direction == 3)
	{
		if (foodArray[closest_food_num].food_y > snake->y)
		{
			snake->direction = 4;
		}
		else if (foodArray[closest_food_num].food_y < snake->y)
		{
			snake->direction = 2;
		}
	}
	else if (snake->direction == 2 || snake->direction == 4)
	{
		if (foodArray[closest_food_num].food_x > snake->x)
		{
			snake->direction = 3;
		}
		else if (foodArray[closest_food_num].food_x < snake->x)
		{
			snake->direction = 1;
		}
	}
}

//----------------------------------------------------------------//
menuTable initMenu(menuTable *menu)
{
    menu->pointer[0] = 1;
    menu->pointer[1] = 0;
    menu->pointer[2] = 0;

    menu->menuLines[0] = 'p';
    menu->menuLines[1] = 'a';
    menu->menuLines[2] = 'q';
}

void printMenu(menuTable *menu)
{
    printf("------------------MENU------------------\n\n\n");
    for (int i = 0; i < 3; i++)
    {
        if (menu->pointer[i] == 1)
        {
            printf("-->  ");
        }
        else
        {
            printf("     ");
        }
        if (menu->menuLines[i] == 'p')
        {
            printf("PLAY\n");
        }
        else if (menu->menuLines[i] == 'a')
        {
            printf("SECOND SNAKE MODE --> AUTO\n");
        }
        else if (menu->menuLines[i] == 's')
        {
            printf("SECOND SNAKE MODE --> PLAYER\n");
        }
        else if (menu->menuLines[i] == 'q')
        {
            printf("QUIT\n");
        }
    }
    printf("\n\n");
    printf("---------------------------------------\n");
    printf("Use W and D to move and SPACE to enter\n\n\n");
}

int menuSelect(menuTable *menu)
{
    int currentPosition = 0;
    char key;
    int endMenu = 0;

    while (!endMenu){
        system("clear");
        printMenu(menu);
        key = getch();
        if (key == 'w')
        {
            currentPosition--;
            if (currentPosition < 0)
            {
                currentPosition = 2;
            }
        }
        else if (key == 's')
        {
            currentPosition++;
            if (currentPosition > 2)
            {
                currentPosition = 0;
            }
        }
        else if (key == ' ')
        {
            if (currentPosition == 0 || currentPosition == 2)
            {
                endMenu = 1;
            }
            else if (currentPosition == 1 && menu->menuLines[1] == 'a')
            {
                menu->menuLines[1] = 's';
            }
            else if (currentPosition == 1 && menu->menuLines[1] == 's')
            {
                menu->menuLines[1] = 'a';
            }
        }

        for (int i = 0; i < 3; i++)
        {
            menu->pointer[i] = 0;
        }
        menu->pointer[currentPosition] = 1;
    }    
    return currentPosition;
}
//----------------------------------------------------------------//


int main(void)
{
	int secondSnakeMode = 1;
    int menuChose = 2;

	int snake_start_x = 7;
	int snake_start_y = 5;
	int snake_start_length = 4;

	int snake2_start_x = 7;
	int snake2_start_y = 10;
	int snake2_start_length = 4;

	menuTable mainMenu;
    initMenu(&mainMenu);
	menuChose =  menuSelect(&mainMenu);

	if (menuChose == 0)
    {
        if (mainMenu.menuLines[1] == 's') secondSnakeMode = 0;
    
		struct timespec snake_delay, snake_delay2;
		snake_delay.tv_sec = 0;
		snake_delay.tv_nsec = 500000000;

		int foodAmount = 5;
		struct food_t foodArray[foodAmount];
		initFood(foodArray, foodAmount, snake_start_y);

		struct snake_t snake = initSnake(snake_start_x, snake_start_y, snake_start_length);
		struct snake_t snake2 = initSnake(snake2_start_x, snake2_start_y, snake2_start_length);
		printSnakeAndFood(snake, snake2, foodArray, foodAmount);
		char dir_key = 'a';




		while(snake.speed <= foodAmount)
		{
			if (kbhit())
			{
				dir_key = getch();
				turnSnake(&snake, &snake2, dir_key);
			}
			if (secondSnakeMode)
			{
				autoSnake(&snake2, foodArray, foodAmount);
			}

			snake = moveSnake(snake);
			snake2 = moveSnake(snake2);
			if (foodIsEaten(&snake, &snake2, foodArray, foodAmount))
			{
				snake_delay.tv_nsec /= snake.speed;
			}
			system("clear");
			printSnakeAndFood(snake, snake2, foodArray, foodAmount);
			nanosleep(&snake_delay, &snake_delay2);
		}
	}
	//printf("Current level: %d\n", snake.speed - 1);
	return 0;
}