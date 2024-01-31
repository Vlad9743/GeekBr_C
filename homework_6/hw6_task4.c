//Задача 4.Все нечетные
#include<stdio.h>

void print_odds(void)
{
    int a;
    int current_num = 0;
    while ((a = getchar()) != '0')
    {

        if (a != ' ')
        {
            current_num = current_num * 10 + (a - 48);
        }

        else
        {
            if (current_num % 2)
            {
                printf("%d ", current_num);
            }
            current_num = 0;
        }
        
    }
    
}

int main()
{
    print_odds();
    return 0;
}