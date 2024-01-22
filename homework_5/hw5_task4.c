//Задача4. Сумма от 1 до N
#include <stdio.h>

int sum_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main(void)
{
    int num = 0, sum = 0;
    printf("Input number: ");
    scanf("%d", &num);
    sum = sum_to_n(num);
    printf("Sum: %d\n", sum);

    return 0;
}