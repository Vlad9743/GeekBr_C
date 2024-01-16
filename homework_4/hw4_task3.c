//Задача 3.Все цифры четные
#include <stdio.h>

int main(void)
{
    int number = 0;
    int is_even = 1;

    printf("Input number: ");
    scanf("%d", &number);

    while (number > 0)
    {
        if ((number % 10) % 2 != 0)
        {
            is_even = 0;
            break;
        }
        number /= 10;
        //printf("+\n");
    }
    
    if (is_even)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

}