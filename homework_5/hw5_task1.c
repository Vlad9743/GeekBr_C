//Задача1. Сколько зерен на доске?
#include <stdio.h>

int grain_count(int square_number)
{
    int grains_quantity = 1;
    for (int i = 1; i < square_number; i++)
    {
        grains_quantity *= 2;
    }
    return grains_quantity;
}

int main(void)
{
    int squre_num = 0;
    printf("Enter the square number: ");
    scanf("%d", &squre_num);
    int grains_quant = grain_count(squre_num);
    printf("Grains quantity: %d\n", grains_quant);
}