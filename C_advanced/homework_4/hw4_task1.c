//Задание 1. Биномиальный коэффициент

#include <stdio.h>

double factorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        double factorial = 1;
        for (int i = 1; i <= number; i++)
        {
            factorial *= i;
        }
        return factorial;
    }
}

int main(void)
{
    int number1, number2;
    printf("Input two numbers: ");
    scanf("%d %d", &number1, &number2);
    double res = factorial(number1) / (factorial(number2)*factorial(number1 - number2));
    printf("Binominal coef: %.0f\n", res);

    return 0;
}