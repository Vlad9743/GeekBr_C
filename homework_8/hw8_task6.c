// Задача 6. Больше среднего

#include <stdio.h>

double MainDiagonalAvg(int size, int a[size][size])
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += a[i][i];
    }
    
    return ((double) sum)/size;
}

int NumberOfPositiveAboveAvg(int size, int a[size][size], double avg)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] > 0 && a[i][j] > avg)
            {
                counter++;
            }
        }
    }
    
    return counter;
}

int main(void)
{
    int array[5][5] = {
        {1, 3, 5, 6 ,9},
        {6, 7, 1, 6, 8},
        {-11, 7, -5, 12, 4},
        {15, 2, 4, 7, 9},
        {12, 7, 9, 2, 3}
    };

    double matrixDiagAvg = MainDiagonalAvg(sizeof(array) / sizeof(array[0]), array);
    int numAboveAvg = NumberOfPositiveAboveAvg(sizeof(array) / sizeof(array[0]), array, matrixDiagAvg);
    printf("Diag Average = %f\n", matrixDiagAvg);
    printf("Number of elements above average = %d\n", numAboveAvg);
}