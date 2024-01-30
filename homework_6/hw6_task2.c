//Задача 2.От A до B
#include<stdio.h>

void print_num(int a, int b)
{
    printf("%d ", a);
    if (a != b)
    {
        if (a < b)
        {
            a++;
            print_num(a, b);
        }
        else 
        {
            a--;
            print_num(a, b);
        }
    }
    
}

int main()
{
    int num1 = 0, num2 = 0;
    printf("Input two numbers: ");
    scanf("%d%d", &num1, &num2);
    print_num(num1, num2);
    return 0;
}