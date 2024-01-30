//Задача 5. Сколько раз встречается символ a
#include<stdio.h>

int acounter(void)
{  
    char a = getchar();
    if (a == '.')
    {
        return 0;
    }
    return (a == 'a') + acounter();
}

int main()
{
    int result = acounter();
    printf("Result: %d\n", result);
    return 0;
}