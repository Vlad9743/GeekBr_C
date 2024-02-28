//Задача 2. Удалить пробелы из текста

#include <stdio.h>
#include <string.h>

int errase_spaces(char *input_string, int input_string_size)//return actual size without excess spaces
{
    char modified_string[input_string_size];

    //find first not space simbol
    int start = 0;
    while(input_string[start] == ' ' && start < input_string_size)
    {
        start++;
    }

    int j = 0;
    for (int i = start; i < input_string_size; i++)
    {
        if (input_string[i] != ' ')
        {
            modified_string[j] = input_string[i];
            j++;
        }
        else//skip excess spaces
        {
            while (input_string[i] == ' ')
            {
                i++;
            }
            i--;
            modified_string[j] = ' ';
            j++;
        }
    }

    int actual_size = j;

    //copy to original string
    for (int i = 0; i < actual_size; i++)
    {
        input_string[i] = modified_string[i];
    }

    return actual_size;
}

int main(void)
{
    char original_string[1000];

    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    if (input_file != 0)
    {   
        fscanf(input_file, "%[^\n]", original_string);

        int actual_size = errase_spaces(original_string, strlen(original_string));

        for (int i = 0; i < actual_size; i++)
        {
            fprintf (output_file, "%c", original_string[i]);
        }

        fclose(input_file);
        fclose(output_file);
    }
}