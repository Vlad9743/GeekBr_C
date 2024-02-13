// Задача 3.Максимум в массиве
#include <stdio.h>

int Find_max_array(int size, int a[])
{
    int max = a[0];
    
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
    
}

int main(void)
{
    int array[] = {519, 456, 8, 0, 4582, 682};
    int result = Find_max_array(sizeof(array) / sizeof(array[0]), array);
    printf("Max = %d\n", result);
}