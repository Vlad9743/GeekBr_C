//Задача 1. Сортировка по возрастанию

#include<stdio.h>

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Sort_array(int size, int a[])
{
    for (int i = size - 1; i > 0; i--)
    {
        int temp;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[i])
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
    int array[] = {20, 19,4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    Sort_array(sizeof(array) / sizeof(array[0]), array);
    Print_arr(array, sizeof(array) / sizeof(array[0]));
}