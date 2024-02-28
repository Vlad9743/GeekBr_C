#include <stdio.h>
#include <string.h>

void switch_simbols(char *input_string, int input_string_size)
{
// count number of spaces
    int number_of_spaces = 0;
    for (int i = 0; i < input_string_size; i++)
    {
        if (input_string[i] == ' ')
        {
           number_of_spaces++;
        }
    }

//save string without spaces and spaces positions in original string
    char string_without_spaces[input_string_size - number_of_spaces];
    int spaces_positions[number_of_spaces];

    int j = 0;
    int k = 0;
    for (int i = 0; i < input_string_size; i++)
    {
        if (input_string[i] != ' ')
        {
            string_without_spaces[j] = input_string[i];
            j++;
        }
        else
        {
            spaces_positions[k] = i;
            k++;
        }
    }

//switch simbols
    char temp;
    for (int i = 1; i < sizeof(string_without_spaces); i += 2)
    {
        temp = string_without_spaces[i - 1];
        string_without_spaces[i - 1] = string_without_spaces[i];
        string_without_spaces[i] = temp;
    }

//bring back spaces
    k = 0;
    j = 0;
    for (int i = 0; i < input_string_size; i++)
    {
        if (i != spaces_positions[k])
        {
            input_string[i] = string_without_spaces[j];
            j++;
        }
        else
        {
            input_string[i] = ' ';
            k++;
        }
    }
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

        switch_simbols(original_string, strlen(original_string));

        for (int i = 0; i < strlen(original_string); i++)
        {
            fprintf (output_file, "%c", original_string[i]);
        }

        fclose(input_file);
        fclose(output_file);
    }




}