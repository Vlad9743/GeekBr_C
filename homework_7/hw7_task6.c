//Задача 6. Чаще других

#include<stdio.h>

#define ARR_SIZE 10

void Print_arr(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Find_most_frequent(int a[], int arrSize)
{
    int most_frequent = a[0];
    int counter = 0; 

    for (int i = 0; i < arrSize; i++)
    {
        int temp_counter = 0;
        for (int j = 0; j < arrSize; j++)
        {
            if (a[i] == a[j])
            {
                temp_counter++;
            }
        }

        if (temp_counter > counter)
        {
            most_frequent = a[i];
            counter = temp_counter;
        }
    }

    return most_frequent;
}

int main(void)
{
    int array[ARR_SIZE] = {4, 1, 2, 1, 11, 2, 34, 11, 0, 11};
    int frequent_num;
    //Input_arr(array, ARR_SIZE);
    
    printf("The array: ");
    Print_arr(array, ARR_SIZE);
    frequent_num = Find_most_frequent(array, ARR_SIZE);
    printf("The most frequent number: %d \n", frequent_num);
    return 0;
}