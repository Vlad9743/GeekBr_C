#include <stdio.h>

#define RECORD_LENGTH 25

struct data_record_t
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
};

struct month_characteristics_t
{
    int month_max_temp;
    int month_min_temp;
    float month_avg_temp;
    int month_records;
};

int count_strings_number(FILE *file_name);

int parse_file(FILE *file_name, struct data_record_t data_array[], int array_length);

void month_temp_parameters(struct data_record_t data_array[], int records_number, int month);

void full_temp_parameters(struct data_record_t data_array[], int records_number);

