// Задача 5. Вторая с конца ноль

#include<stdio.h>

#define ARR_SIZE 10

void Input_arr(int a[], int arrSize)
{
    printf("Input %d numbers: ", arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &a[i]);
    }
}

void Print_arr_whithout_zeros(int a[], int arrSize)
{
    int i = 0;
    while (a[i] != 0)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
}

void Filter_second_digit(int a[], int a_filtered[], int arrSize)
{
    int a_filtered_counter = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if ((a[i] % 100) < 10)
        {
            a_filtered[a_filtered_counter] = a[i];
            a_filtered_counter++;
        }
    }
}

int main(void)
{
    int array[ARR_SIZE] = {40, 105 , 203, 1, 14, 1000, 22, 33, 44, 55};
    int filtered_array[ARR_SIZE] = {0};
    //Input_arr(array, ARR_SIZE);
    Filter_second_digit(array, filtered_array, ARR_SIZE);
    Print_arr_whithout_zeros(filtered_array, ARR_SIZE);
    return 0;
}