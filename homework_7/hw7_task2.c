// Задача 2.Найти минимум

#include<stdio.h>

#define ARR_SIZE 5

void Input_arr(int a[], int arrSize)
{
    printf("Input %d numbers: ", arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &a[i]);
    }
}

int My_min(int a[], int arrSize)
{   
    int min = a[0];
    for (int i = 0; i < arrSize; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int main(void)
{
    int array[ARR_SIZE] = {0};
    Input_arr(array, ARR_SIZE);
    int min1 = My_min(array, ARR_SIZE);
    printf("Minimum: %d \n", min1);
    return 0;
}