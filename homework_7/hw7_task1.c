// Задача1.Среднее арифметическое чисел

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

float Average(int a[], int arrSize)
{
    float average = 0;
    for (int i = 0; i < arrSize; i++)
    {
        average += ((float)a[i]/arrSize);
    }
    return average;
}

int main(void)
{
    int array[ARR_SIZE] = {0};
    Input_arr(array, ARR_SIZE);
    float aver1 = Average(array, ARR_SIZE);
    printf("Average: %.3f \n", aver1);
    return 0;
}