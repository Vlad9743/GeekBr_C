//Задание 3. Не пара

//Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000) натуральных чисел,
// не превосходящих 1 000 000. Известно, что ровно одно число в этом наборе встречается один раз,
// а остальные — ровно по два раза. Помогите им найти это число. Входные данные: в первой входной
// строке вводится число N, затем по одному числу в строке вводятся N натуральных чисел, не превосходящих
// 2 000 000 000. Выходные данные: ваша программа должна определить число, встречающееся один раз, и вывести его на экран.

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int quantity = 0;
    printf("Input quantity of numbers: ");
    scanf("%d", &quantity);

    uint32_t result = 0;
    for (int i = 0; i < quantity; i++)
    {
        uint32_t temp = 0;
        printf("Input number: ");
        scanf("%u", &temp);
        
        result = result ^ temp;
    }
    
    printf("Solo number: %u\n", result);

    return 0;
}