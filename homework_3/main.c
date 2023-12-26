//Домашнее задание №3

#include <stdio.h>

int main(void)
{
    // Задача1. Наибольшее из пяти чисел
    printf("Задача1. Наибольшее из пяти чисел\n");
    int n11, n12, n13, n14, n15, max;
    printf("Введите 5 чисел: ");
    scanf("%d%d%d%d%d", &n11, &n12, &n13, &n14, &n15);
    max = n11;
    if (n12 > max) max = n12;
    if (n13 > max) max = n13;
    if (n14 > max) max = n14;
    if (n15 > max) max = n15;
    
    printf("Максимальное число из %d, %d, %d, %d, %d равно %d\n", n11, n12, n13, n14, n15, max);
    printf("\n");

    // Задача2.Наименьшее из пяти чисел
    printf("Задача2.Наименьшее из пяти чисел\n");
    int n21, n22, n23, n24, n25, min;
    printf("Введите 5 чисел: ");
    scanf("%d%d%d%d%d", &n21, &n22, &n23, &n24, &n25);
    min = n21;
    if (n22 < min) min = n22;
    if (n23 < min) min = n23;
    if (n24 < min) min = n24;
    if (n25 < min) min = n25;
    
    printf("Минимальное число из %d, %d, %d, %d, %d равно %d\n", n21, n22, n23, n24, n25, min);
    printf("\n");

    //Задача3. В порядке возрастания
    printf("Задача3. В порядке возрастания\n");
    int n31, n32, n33;
    printf("Введите 3 числа: ");
    scanf("%d%d%d", &n31, &n32, &n33);

    if ((n33 > n32) && (n32 > n31))
    {
        printf("%d - %d - %d ---> YES\n", n31, n32, n33);
    } 
    else
    {
        printf("%d - %d - %d ---> NO\n", n31, n32, n33);
    }
    printf("\n");

    //Задача4. Какое время года
    printf("Задача4. Какое время года\n");
    int month_number;
    printf("Input number: ");
    scanf("%d", &month_number);

    if ((month_number >= 1) && (month_number <= 12))
    {
        if ((month_number == 12) || (month_number == 1) || (month_number == 2)) printf("winter\n");
        if ((month_number >= 3) && (month_number <= 5)) printf("spring\n");
        if ((month_number >= 6) && (month_number <= 8)) printf("summer\n");
        if ((month_number >= 9) && (month_number <= 11)) printf("autumn\n");
    }
    else
    {
        printf("Wrong input.\n");
    }
}





