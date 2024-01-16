//Задача 4. Перевернуть число
#include <stdio.h>

int main(void)
{
    int number = 0;
    int reversed_number = 0;
    int temp = 0;

    printf("Input number: ");
    scanf("%d", &number);

    while (number > 0)
    {
        reversed_number += (number % 10);
        number /= 10;
        reversed_number *= 10;
    }
    reversed_number /= 10;
    
    printf("Reversed number: %d\n", reversed_number);

}