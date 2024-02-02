//Задача 3.Циклический сдвиг массива вправо

#include<stdio.h>

#define ARR_SIZE 12

void Input_arr(int a[], int arrSize)
{
    printf("Input %d numbers: ", arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &a[i]);
    }
}

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Move_right(int a[], int arrSize, int steps_number)
{
    for (int i = 0; i < steps_number; i++)
    {
        int temp = a[arrSize - 1];
        for (int i = arrSize - 1; i >= 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }
}

int main(void)
{
    int array[ARR_SIZE] = {0};
    Input_arr(array, ARR_SIZE);
    Move_right(array, ARR_SIZE, 4);
    Print_arr(array, ARR_SIZE);
    return 0;
}