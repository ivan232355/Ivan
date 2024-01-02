
#include "D:\ECLIPSE_PROJEKT\Emb_Temp\inc\temp_api.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *input_file = NULL;
FILE *file;

double Month_Stat_averge(struct Temp_Data *data, int target_month,int size)
{
    double sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == target_month)
        {
            sum += data[i].temperature;
            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    return sum / count;
}

int Month_Stat_min (struct Temp_Data *data, int target_month,int size)
{
    int min = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == target_month)
        {
        	if (count == 0)
        	{
        		min = data[i].temperature;
        	}

            if (data[i].temperature < min)
            {
            	min = data[i].temperature;
            }
            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    return min;
}
int Month_Stat_max (struct Temp_Data *data, int target_month,int size)
{
    int max = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == target_month)
        {
        	if (count == 0)
        	{
        		max = data[i].temperature;
        	}
            if (data[i].temperature > max)
            {
            	max = data[i].temperature;
            }
            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    return max;
}

void Year_Stat (struct Temp_Data *data,int target_year, int *avTemp, int *minTemp, int *maxTemp,int size)
{
    int max = 0,min = 0;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].year == target_year)
        {
        	sum += data[i].temperature;
        	if (count == 0)
        	{
        		max = data[i].temperature;
        		min = data[i].temperature;
        	}
            if (data[i].temperature > max)
            {
            	max = data[i].temperature;
            }
            if (data[i].temperature < min)
            {
            	min = data[i].temperature;
            }
            count++;
        }
    }
    *avTemp = sum/count;
    *minTemp = min;
    *maxTemp = max;

}
int Open_csv (struct Temp_Data **data, int *records)
{
	//printf("Input file: %s\n", optarg);
	input_file = optarg;
	if (input_file == NULL)
	{
		printf("No input file!\n");
		return 0;
	}
	// Открытие файла для чтения
	if (input_file != NULL)
	{

		if ((file = fopen(input_file, "r")) == NULL)
		{
			printf("Error occured while opening input file!\n");
			return 1;
		}
	    // Подсчет количества строк в файле CSV
	    int count = 0;
	    char c;
	    while ((c = fgetc(file)) != EOF) {
	        if (c == '\n') {
	            count++;
	        }
	    }
	    fseek(file, 0, SEEK_SET); // Возвращаем указатель на начало файла
	    *records = count;
	    *data = malloc(*records * sizeof(*data));// Выделение памяти для массива структур
		GetData_csv(file,*data,*records);	// Получение данных
		// Проверка корректности данных в файле
		if (Checking_data(*data,*records) == 1)
		{
			return 1;
		}
		else
		{
			fclose(file);
			return 0;
		}
	}
	fclose(file);
	return 1;
}

void GetData_csv(FILE *file, struct Temp_Data *data, int records)
{
	char str[32] = {0, }; // Буфер для считывания строки из файла
	char *token;
	int i = 0;
// заполняем структуру значениями по признаку ;
	while (fgets(str, sizeof(str), file) && i < records)
	{

		token = strtok(str, ";");
		data[i].year = atoi(token);
		token = strtok(NULL, ";");
		data[i].month = atoi(token);
		token = strtok(NULL, ";");
		data[i].day = atoi(token);
		token = strtok(NULL, ";");
		data[i].hour = atoi(token);
		token = strtok(NULL, ";");
		data[i].minute = atoi(token);
		token = strtok(NULL, ";");
		data[i].temperature = atoi(token);
		i++;

	}

	printf("\n");
	for (i = 0; i < records; i++)
	{
		printf("Year: %hu ", data[i].year);
		printf("Month: %hu ", data[i].month);
		printf("Day: %hu ", data[i].day);
		printf("Hour: %hu ", data[i].hour);
		printf("Minute: %hu ", data[i].minute);
		printf("Temp: %hd\n", data[i].temperature);
	}

}

int Checking_data(struct Temp_Data *data, int records)
{
	uint8_t flag_error = 0;
    for (int i = 0; i < records; i++)
    {
        if ((data[i].year < 1000) || (data[i].year > 9999) || (data[i].month > 12) || (data[i].month <= 0)
        		|| (data[i].day > 31) || (data[i].hour > 24) || (data[i].minute > 60))
        {
            printf("Error: Incorrect data format chek the line %d\n", i+1);
            flag_error = 1;

        }

    }
    if (flag_error == 1)
    	return 0;
    return 1;
}

