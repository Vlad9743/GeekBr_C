// Задача 2. Заменить a на b

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    char original_string[1000];
    int i = 0;
    char temp;

    while ((temp = fgetc(input_file)) != EOF)
    {
        original_string[i] = temp;
        i++;
    }

     for (int i = 0; i < strlen(original_string); i++)
    {
        if (original_string[i] == 'a')
        {
            temp = 'b';
        }
        else if (original_string[i] == 'A')
        {
            temp = 'B';
        }
        else if (original_string[i] == 'b')
        {
            temp = 'a';
        }
        else if (original_string[i] == 'B')
        {
            temp = 'A';
        }
        else
        {
            temp = original_string[i];
        }
        
        fprintf(output_file, "%c", temp);
    }

    fclose(input_file);
    fclose(output_file);
}