#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

void printScore(int pumpkinGathered, int pumpkinDestroied);

int getch( );

int kbhit();