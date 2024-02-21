// Задача 4. Удалить повторяющиеся символы

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    int i = 0;
    char temp;
    char result_string[1000] = {0};
    int res_string_index = 0;
    int not_found;

    while ((temp = fgetc(input_file)) != EOF)
    {   
        not_found = 1;

        for (int j = 0; j < strlen(result_string); j++)
        {
            if (temp == result_string[j])
            {
                not_found = 0;
            }
        }
        if (not_found && temp != ' ')
        {
            result_string[res_string_index] = temp;
            res_string_index++;
        }
    }

    for (int i = 0; i < strlen(result_string); i++)
    {
        fprintf (output_file, "%c", result_string[i]);
    }

    fclose(input_file);
    fclose(output_file);

}