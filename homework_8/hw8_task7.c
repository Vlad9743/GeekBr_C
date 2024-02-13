//Задача 7*. Клетки

#include <stdio.h>

void BlackOrWhite(int size, char a[])
{
    if (a[0] >= 65 && a[0] <= 72 && a[1] >= 49 && a[1] <= 56)
    {
        if ((((int)a[0]) % 2 != 0 && ((int)a[1]) % 2 != 0) || (((int)a[0]) % 2 == 0 && ((int)a[1]) % 2 == 0))
        {
            printf("BLACK\n");
        }
        else
        {
            printf("WHITE\n");
        }
    }
    else
    {
        printf("Wrong coordinates.\n");
    }
}


int main(void)
{
    printf("Input coordinate: ");
    char coord[2];
    scanf("%s", coord);

    BlackOrWhite(sizeof(coord) / sizeof(coord[0]), coord);

}