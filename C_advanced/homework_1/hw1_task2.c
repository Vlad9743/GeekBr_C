//Задание 2. Инверсия старших

//На вход программе подается беззнаковое 32-битное целое число N. 
//Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.

#include <stdio.h>
#include <stdint.h>

void pring_binary(uint32_t num)
{
    int bin_array[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        bin_array[31 - i] = num % 2;
        num /= 2;
    }
    for (int i = 0; i < 32; i++)
    {
        printf("%d ", bin_array[i]);
    }
    printf("\n");
}

int main(void)
{
    uint32_t original_num = 0;
    printf("Input number: ");
    scanf("%u", &original_num);

    printf("Original num:        ");
    pring_binary(original_num);

    uint32_t first_byte = ~original_num;
    first_byte = first_byte >> 24 << 24;
    uint32_t last_bytes = original_num << 8 >> 8;

    printf("First byte inverted: ");
    pring_binary(first_byte);

    printf("Last bytes:          ");
    pring_binary(last_bytes);

    uint32_t result = first_byte | last_bytes;

    printf("Result binary:       ");
    pring_binary(result);

    printf("Result decimal:      %u\n", result);

    return 0;
}