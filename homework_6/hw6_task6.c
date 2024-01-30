//Задача 6. Возвести в степень
#include<stdio.h>

__int64_t recurs_power(int n, int p)
{
    if (p > 1)
    {
        return n*recurs_power(n, --p);
    }
    return n;
}

int main()
{
    signed int base = 1;
    unsigned int power = 1;
    printf("Input base: ");
    scanf("%d", &base);
    printf("Input power: ");
    scanf("%u", &power);
    __int64_t result = recurs_power(base, power);
    printf("%ld\n", result);
    return 0;
}