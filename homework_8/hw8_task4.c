// Задача4.Два одинаковых

#include <stdio.h>

int Is_two_same(int size, int a[])
{
    int has_copy = 0;
    int i = 0;

    while (i < size && !has_copy)
    {
        int j = 0;
        for (j; j < size; j++)
        {
            if (a[i] == a[j] && i != j)
            {
                has_copy = 1;
            }
        }
        i++;
    }
    
    return has_copy;
    
}

int main(void)
{
    int array[] = {519, 456, 8, 0, 4582, 682, 8};
    int result = Is_two_same(sizeof(array) / sizeof(array[0]), array);
    
    if (result)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }   
}