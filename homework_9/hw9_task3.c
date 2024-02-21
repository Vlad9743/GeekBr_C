// Задача 3.Числа в массив

#include <stdio.h>
#include <string.h>

void Sort_array(int size, int a[])
{
    for (int i = size - 1; i > 0; i--)
    {
        int temp;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    int result_array[100] = {};
    int res_array_index = 0;
    char temp;
    int temp_number = 0;
    int number_found = 0;

    while ((temp = fgetc(input_file)) != EOF)
    {   
        if (temp <= '9' && temp >= '0')
        {
            temp_number = temp_number * 10 + (temp - '0');
            number_found = 1;
        }
        else if (number_found)
        {
        result_array[res_array_index] = temp_number;
        temp_number = 0;
        res_array_index++;
        number_found = 0;
        }
    }

    Sort_array(res_array_index, result_array);

    for (int i = 0; i < res_array_index; i++)
    {
        fprintf (output_file, "%d ", result_array[i]);
    }

    fclose(input_file);
    fclose(output_file);
}