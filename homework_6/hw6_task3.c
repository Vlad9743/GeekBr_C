//Задача 3. Количество 1
#include<stdio.h>

int count_one(int num)
{

   if (num <= 2) 
   {
        return 1;
   }
   
   return 1 + count_one(num / 2);

}

int main()
{
    int number = 0;
    printf("Input number: ");
    scanf("%d", &number);
    int result = count_one(number);
    printf("Result: %d \n", result);
    
    return 0;
}