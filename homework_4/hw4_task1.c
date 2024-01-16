//Задача 1. Сумма квадратов маленьких чисел
#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, temp = 0;
    printf("Input two numbers: ");
    scanf("%d%d", &a, &b);

    if (b < a)
    {
        temp = a;
        a = b;
        b = temp;
    }

    int result = 0;
    while (a <= b)
    {
        result += (a*a);
        a++;
    }

    printf("Result: %d \n", result);
    
}