//Задача 4.Отсортировать по последней цифре

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

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Sort_last_digit(int a[], int arrSize)
{
    for (int i = arrSize - 1; i > 0; i--)
    {
        int temp;
        for (int j = i - 1; j >= 0; j--)
        {
            if ((a[j] % 10) > (a[i] % 10))
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
            
        }
    }
}

int main(void)
{
    int array[ARR_SIZE] = {109, 118, 100, 51, 62, 73, 1007, 16, 4, 555};
    Input_arr(array, ARR_SIZE);
    Sort_last_digit(array, ARR_SIZE);
    Print_arr(array, ARR_SIZE);
    return 0;
}