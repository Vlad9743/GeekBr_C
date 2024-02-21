// Задача 5. Самое длинное слово

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    char new_string[1000];
    int word_end;
    char temp;
    int max_length = 0;
    int current_length = 0;
    int current_simbol_index = 0;

    while ((temp = fgetc(input_file)) != EOF)
    {
        if (temp == ' ')
        {
            if (current_length > max_length)
            {
                max_length = current_length;
                word_end = current_simbol_index;
                current_length = 0;
                 
            }
        }
        current_length++;
        current_simbol_index++;
    }

    //дополнительая проверка, иначе не отрабатывается последнее слово
    if (current_length > max_length)
    {
        max_length = current_length;
        word_end = current_simbol_index;
    }
    
    fseek(input_file, word_end - max_length, SEEK_SET);
    for (int i = 0; i < max_length; i++)
    {
        temp = fgetc(input_file);
        fprintf(output_file, "%c", temp);
    }

    fclose(input_file);
    fclose(output_file);
}