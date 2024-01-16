// Задача 5. Все счастливые числа
#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("Input number: ");
    scanf("%d", &number);

    for (int i = 10; i <= number; i++)
    {
        int current_num = i, temp_sum = 0, temp_mult = 1;
        while(current_num > 0)
        {
            temp_sum += (current_num % 10);
            temp_mult *= (current_num % 10);
            current_num /= 10;
        }
        if (temp_sum == temp_mult)
        {
            printf("%d ", i);
        }
    }

}