//Задача2. НОД
#include <stdio.h>

int nod(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    return a + b;
    
}

int main(void)
{
    int num1 = 0, num2 = 0;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    int nod_result = nod(num1, num2);
    printf("Divider: %d\n", nod_result);

    return 0;
}