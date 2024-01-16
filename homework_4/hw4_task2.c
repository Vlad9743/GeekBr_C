//Задача 2. Ровно три цифры
#include <stdio.h>

int main(void)
{
    int number = 0, counter = 0;
    printf("Input number: ");
    scanf("%d", &number);

    while (number > 0)
    {
        number /= 10;
        counter++;
    }
    
    if (counter == 3)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}