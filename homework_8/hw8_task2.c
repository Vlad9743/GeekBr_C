// Задача 2.Четные в начало

#include <stdio.h>

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Sort_even_odd(int n, int a[])
{
    int temp_counter = 0;
    int temp_array[n];

    //gathering odds
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            temp_array[temp_counter] = a[i];
            temp_counter++;
        }
    }
    
    //gathering evens
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            temp_array[temp_counter] = a[i];
            temp_counter++;
        }
    }

    //copying back to original array
    for (int i = 0; i < n; i++)
    {
        a[i] = temp_array[i];
    }
}

int main(void)
{
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array1[] = {1, 0, 1, 0, 1};
    Sort_even_odd(sizeof(array) / sizeof(array[0]), array);
    Sort_even_odd(sizeof(array1) / sizeof(array1[0]), array1);
    Print_arr(array, sizeof(array) / sizeof(array[0]));
    Print_arr(array1, sizeof(array1) / sizeof(array1[0]));
}
