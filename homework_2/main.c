#include<stdio.h>

int main(void)
{
    //Задача1.Сумма трех чисел
    printf("Задача1.Сумма трех чисел\n");
    int a, b, c;
    printf("Введите три числа: ");
    scanf("%d%d%d", &a, &b, &c);
    int sum = a + b + c;
    printf("%d + %d + %d = %d\n", a, b, c, sum);

    //Задача2.Сумма и произведение трех чисел
    printf("Задача2.Сумма и произведение трех чисел\n");
    int a1, b1, c1;
    printf("Введите три числа: ");
    scanf("%d%d%d", &a1, &b1, &c1);
    int sum_1 = a1 + b1 + c1;
    int multi_1 = a1 * b1 * c1;
    printf("%d + %d + %d = %d\n", a1, b1, c1, sum_1);
    printf("%d * %d * %d = %d\n", a1, b1, c1, multi_1);

    //Задача3.Разность двух чисел
    printf("Задача3.Разность двух чисел\n");
    int a2, b2;
    printf("Введите два числа: ");
    scanf("%d%d", &a2, &b2);
    int sub_2 = a2 - b2;
    printf("%d - %d = %d\n", a2, b2, sub_2);

    //Задача4. Найти среднее арифметическое цифр числа
    printf("Задача4. Найти среднее арифметическое цифр числа\n");
    int a3, sum_3 = 0; 
    float average_3 = 0;
    printf("Введите четырехзначное целое положительное число:");
    scanf("%d", &a3);
    for (int i = 0; i < 4; i++)
    {
        sum_3 += a3 % 10;
        a3 /= 10;
    }
    average_3 = sum_3/4.;
    printf("Среднее фрифметическое цифр = %.2f\n", average_3);

return 0;
}