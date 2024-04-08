#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <unistd.h>
#include <termios.h>

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
}  snake_t;

struct snake_t initSnake(int x, int y, size_t tsize){
	struct snake_t snake;
    snake.direction = 1;
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

void printSnake(struct snake_t snake){
	char matrix[MAX_X][MAX_Y];
	for (int i = 0; i < MAX_X; ++i){
		for (int j = 0; j < MAX_Y; ++j)
		{
			matrix[i][j] = ' ';
		}
    }
		
	matrix[snake.x][snake.y] = '@';
	for (int i = 0; i < snake.tsize; ++i){
	    matrix[snake.tail[i].x][snake.tail[i].y] = '*';
	}
		
	for (int j = 0; j < MAX_Y; ++j){
		for (int i = 0; i < MAX_X; ++i)
		{
			printf("%c", matrix[i][j]);
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

snake_t turnSnake(snake_t snake, char key)
{
	if ((key == 'a' || key == 'A') && (snake.direction != 3))
    {
        snake.direction = 1;
    }
    else if ((key == 'w' || key == 'W') && (snake.direction != 4))
    {
        snake.direction = 2;
    }
    else if ((key == 'd' || key == 'D') && (snake.direction != 1))
    {
        snake.direction = 3;
    }
    else if ((key == 's' || key == 'S') && (snake.direction != 2))
    {
        snake.direction = 4;
    }

	return snake;
}


int main(void)
{

	struct snake_t snake = initSnake( 10, 5, 5);
	printSnake(snake);
    char dir_key = 'a';

	while(1)
	{
        dir_key = getch();
        snake = turnSnake(snake, dir_key);
		snake = moveSnake(snake);
		//sleep(1);
		printSnake(snake);
	}

	return 0;
}