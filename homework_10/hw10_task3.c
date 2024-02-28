//Задача 3. Изменить расширение

#include <stdio.h>
#include <string.h>

int change_extension(char *input_string, int input_string_size)//return string size without extension
{
    int last_dot_position = input_string_size - 1;
    int point_found = 0;
    

    while (!point_found && last_dot_position > 0)
    {
        if (input_string[last_dot_position] == '.')
        {
            point_found = 1;
        }
        else if (input_string[last_dot_position] == 47)
        {
            point_found = 1;
            last_dot_position = input_string_size;
        }
        
        last_dot_position--;
    }
    
    return last_dot_position + 1;
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

        int actual_size = change_extension(original_string, strlen(original_string));

        char new_extension[] = ".html";
  
        for (int i = 0; i < actual_size; i++)
        {
            fprintf (output_file, "%c", original_string[i]);
        }
        
        fprintf (output_file, "%s", new_extension);

        fclose(input_file);
        fclose(output_file);
    }
}