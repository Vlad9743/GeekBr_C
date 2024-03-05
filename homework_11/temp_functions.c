#include "temp_functions.h"

int count_strings_number(FILE *file_name)
{   
    __int64_t strings_number = 0;
    char temp_strinng[RECORD_LENGTH];
            
    while (fgets(temp_strinng, RECORD_LENGTH, file_name) != NULL)
    {
        strings_number++;
    }
    fseek(file_name, 0, SEEK_SET);
    return strings_number;
}

int parse_file(FILE *file_name, struct data_record_t data_array[], int array_length)
{
    int loc_year, loc_month, loc_day, loc_hour, loc_minute, loc_temperature;
    int current_record = 0;
    int actual_records = 0;
       
    for (current_record; current_record < array_length; current_record++)
    {   
        int args_num = 0; 
        args_num = fscanf(file_name, "%d;%d;%d;%d;%d;%d", 
           &loc_year,
           &loc_month, 
           &loc_day,
           &loc_hour,
           &loc_minute,
           &loc_temperature);

        if (args_num < 6)
        {
            char s[RECORD_LENGTH];
            int r = fscanf(file_name, "%[^\n]", s);
            printf("Corrupted data in line %d.\n", current_record + 1);
        }
        else
        {
            if (loc_year >= 2015 && loc_year <= 2025 &&
                loc_month >= 1 && loc_month <= 12 &&
                loc_day >= 1 && loc_day <= 31 &&
                loc_hour >= 0 && loc_hour <= 24 &&
                loc_minute >= 0 && loc_minute <= 59 &&
                loc_temperature >= -99 && loc_temperature <= 99)
            {    
                data_array[actual_records].year = loc_year;
                data_array[actual_records].month = loc_month;
                data_array[actual_records].day = loc_day;
                data_array[actual_records].hour = loc_hour;
                data_array[actual_records].minute = loc_minute;
                data_array[actual_records].temperature = loc_temperature;
                actual_records++;
            }
            else
            {
                printf("Corrupted data in line %d.\n", current_record + 1);
            }
        }
    }
    return actual_records;
}

void month_temp_parameters(struct data_record_t data_array[], int records_number, int month)
{
    int max = -99;
    int min = 99;
    __int64_t sum = 0;
    int records_in_month = 0;

    for (int i = 0; i < records_number; i++)
    {
        if (data_array[i].month == month)
        {
            if (data_array[i].temperature > max)
            {
                max = data_array[i].temperature;
            }
            if (data_array[i].temperature < min)
            {
                min = data_array[i].temperature;
            }
            records_in_month++;
            sum += data_array[i].temperature;
        }
    }

    if (records_in_month == 0)
    {
        printf("No records for month %d.\n", month);
    }
    else
    {
        printf("Month %d. Max temp: %d. Min temp: %d. Avg temp: %.3f\n", month, max, min, (float)sum/records_in_month);
    }
}

void full_temp_parameters(struct data_record_t data_array[], int records_number)
{
    struct month_characteristics_t charecteristics[12];
    for (int i = 0; i < 12; i++)
    {
        charecteristics[i].month_max_temp = -99;
        charecteristics[i].month_min_temp = 99;
        charecteristics[i].month_avg_temp = 0.0;
        charecteristics[i].month_records = 0;
    }
    int current_month = 0;
    for (int i = 0; i < records_number; i++)
    {
        current_month = data_array[i].month;
        
            if (data_array[i].temperature > charecteristics[current_month - 1].month_max_temp)
            {
                charecteristics[current_month - 1].month_max_temp = data_array[i].temperature;
            }
            if (data_array[i].temperature < charecteristics[current_month - 1].month_min_temp)
            {
                charecteristics[current_month - 1].month_min_temp = data_array[i].temperature;
            }
            charecteristics[current_month - 1].month_records++;
            charecteristics[current_month - 1].month_avg_temp += data_array[i].temperature;
    }

    int year_max_temp = -99;
    int year_min_temp = 99;
    int actual_month = 12;
    float year_avg_temp = 0;
    for (int i = 0; i < 12; i++)
    {
        if (charecteristics[i].month_records == 0)
        {
            printf("No records for month %d.\n", i + 1);
            charecteristics[i].month_avg_temp = 0;
            actual_month--;
        }
        else
        {
            printf("Month %d. Max temp: %d.", i + 1, charecteristics[i].month_max_temp);
            printf("Min temp: %d. ", charecteristics[i].month_min_temp);
            printf("Avg temp: %.3f\n", charecteristics[i].month_avg_temp/charecteristics[i].month_records);
        }

        if (charecteristics[i].month_max_temp > year_max_temp)
        {
            year_max_temp = charecteristics[i].month_max_temp;
        }
        if (charecteristics[i].month_min_temp < year_min_temp)
        {
            year_min_temp = charecteristics[i].month_min_temp;
        }
        if ((charecteristics[i].month_records != 0))
        {
            year_avg_temp += charecteristics[i].month_avg_temp/charecteristics[i].month_records;
        }
    }
    year_avg_temp /= actual_month;

    printf("============================================\n");
    printf("Year max temp: %d. Year min temp: %d. Year average temp: %.6f\n", year_max_temp, year_min_temp, year_avg_temp);
}