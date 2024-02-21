//Задача 6. Заканчивается на a

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    char new_string[1000];
    new_string[0] = fgetc(input_file);
    //char temp;
    int current_simbol_index = 1;
    int words_counter = 0;

    while ((new_string[current_simbol_index] = fgetc(input_file)) != EOF)
    {
        if (new_string[current_simbol_index] == ' ' && new_string[current_simbol_index - 1] == 'a')
        {
            words_counter++;
        }
        current_simbol_index++;
    }

    if (new_string[strlen(new_string)-2] == 'a')
    {
        words_counter++;
    }

    fprintf(output_file, "%d", words_counter);

    fclose(input_file);
    fclose(output_file);
}