//Задача 1. В прямом порядке
#include<stdio.h>

void print_num(int num)
{
    if (num >= 10)
    {
        print_num(num / 10);
    }
    printf("%d ", num % 10);
}

int main()
{
    int number = 0;
    printf("Input number: ");
    scanf("%d", &number);
    print_num(number);
    printf("\n");
    return 0;
}