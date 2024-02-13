// Задача 5.Поменять местами

#include <stdio.h>

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%5d ", a[i]);
    }
    printf("\n");
}

void Change_max_min(int size, int a[])
{
    int max = a[0];
    int min = a[0];
    int max_index = 0;
    int min_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_index = i;
        }

           if (a[i] < min)
        {
            min = a[i];
            min_index = i;
        }
    }

    int temp = a[max_index];
    a[max_index] = a[min_index];
    a[min_index] = temp;
    
}

int main(void)
{
    int array[] = {5191, 456, 8, 5, 4582, 682, 8};
    Print_arr(array, sizeof(array) / sizeof(array[0]));
    Change_max_min(sizeof(array) / sizeof(array[0]), array);
    Print_arr(array, sizeof(array) / sizeof(array[0]));
}

