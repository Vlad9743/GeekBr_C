//Задача 1. По одному разу

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file;
    input_file = fopen("test.txt", "r");
    FILE *output_file;
    output_file = fopen("test_out.txt", "w");

    char word_one[100];
    char word_two[100];
    char result_simbols[100];
    char temp;
    int i = 0;
    int res_simbols_index = 0;

    //read word one
    while ((temp = fgetc(input_file)) != ' ')
    {
        word_one[i] = temp;
        i++;
    }

    //read word two
    i = 0;
    while ((temp = fgetc(input_file)) != EOF)
    {
        word_two[i] = temp;
        i++;
    }

    //check simbols quantity
    for (int j = 0; j < strlen(word_one); j++)
    {
        temp = word_one[j];
        int count_in_word_one = 0;
        int count_in_word_two = 0;
        for (int k = 0; k < strlen(word_one); k++)
        {
            if (temp == word_one[k])
            {
                count_in_word_one++;
            }
        }
        if (count_in_word_one == 1)
        {
            for (int m = 0; m < strlen(word_two); m++)
            {
                if (temp == word_two[m])
                {
                    count_in_word_two++;
                }
            }
        }
        if (count_in_word_one == 1 && count_in_word_two == 1)
        {
            result_simbols[res_simbols_index] = temp;
            res_simbols_index++;
        }
    }

    //sort result array
    for (int i = strlen(result_simbols) - 1; i > 0; i--)
    {
        char sort_temp;
        for (int j = i - 1; j >= 0; j--)
        {
            if (result_simbols[j] > result_simbols[i])
            {
                sort_temp = result_simbols[j];
                result_simbols[j] = result_simbols[i];
                result_simbols[i] = temp;
            }
        }
    }
    
    //write result simbols to file
    for (int i = 0; i < strlen(result_simbols); i++)
    {
        fprintf (output_file, " %c", result_simbols[i]);
    }

    fclose(input_file);
    fclose(output_file);
}