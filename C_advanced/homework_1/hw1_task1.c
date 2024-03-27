//Задание 1. Сколько раз встречается максимум

//На стандартном потоке ввода задается натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
//На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int quantity = 0;
    printf("Input quantity of numbers: ");
    scanf("%d", &quantity);

    int32_t max = INT32_MIN;
    uint32_t max_count = 0;
    for (int i = 0; i < quantity; i++)
    {
        int32_t temp = 0;
        printf("Input number: ");
        scanf("%d", &temp);
        
        if (temp == max)
        {
            max_count++;
        }
        else if (temp > max)
        {
            max = temp;
            max_count = 1;
        }
    }

    printf("Maximum: %d\n", max);
    printf("Quantity of maximums: %u\n", max_count);
    return 0;
}