// Задача3.Сумма цифр равна произведению
#include <stdio.h>

int is_happy_number(int n)
{
    int sum = 0, mult = 1;
    while(n > 0)
    {
        sum += (n % 10);
        mult *= (n % 10);
        n /= 10;
    }
    if (sum == mult)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int number = 0;
    printf("Enter number: ");
    scanf("%d", &number);
    if (is_happy_number(number))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}