
#include "D:\ECLIPSE_PROJEKT\Emb_Temp\inc\temp_api.h"
#include <stdint.h>

struct Temp_Data data_csv[16];

char *input_file = NULL;
FILE *file;

int Month_Stat_averge(struct Temp_Data data[], int target_month,uint8_t size)
{
    int sum = 0;
    int count = 0;

    for (uint8_t i = 0; i < size; i++)
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

    return (int)sum / count;
}

int Month_Stat_min (struct Temp_Data data[], int target_month,uint8_t size)
{
    int min = 0;
    int count = 0;

    for (uint8_t i = 0; i < size; i++)
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
int Month_Stat_max (struct Temp_Data data[], int target_month,uint8_t size)
{
    int max = 0;
    int count = 0;

    for (uint8_t i = 0; i < size; i++)
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

void Year_Stat (struct Temp_Data data[],int target_year, int *avTemp, int *minTemp, int *maxTemp,uint8_t size)
{
    int max = 0,min = 0;
    int sum = 0;
    int count = 0;

    for (uint8_t i = 0; i < size; i++)
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
int Open_csv(void)
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

		GetData_csv(file);
	}
	fclose(file);
	return 1;
}

void GetData_csv(FILE *file)
{
	char str[32] = { 0, }; // Буфер для считывания строки из файла
	char *token;
	int i = 0;
// заполняем структуру значениями по признаку ;
	while (fgets(str, sizeof(str), file))
	{

		printf("%s", str); // вывод строки str
		token = strtok(str, ";");
		data_csv[i].year = atoi(token);
		token = strtok(NULL, ";");
		data_csv[i].month = atoi(token);
		token = strtok(NULL, ";");
		data_csv[i].day = atoi(token);
		token = strtok(NULL, ";");
		data_csv[i].hour = atoi(token);
		token = strtok(NULL, ";");
		data_csv[i].minute = atoi(token);
		token = strtok(NULL, ";");
		data_csv[i].temperature = atoi(token);
		i++;

	}

	printf("\n");
	for (i = 0; i < 16; i++)
	{
		printf("Year: %hu ", data_csv[i].year);
		printf("Month: %hu ", data_csv[i].month);
		printf("Day: %hu ", data_csv[i].day);
		printf("Hour: %hu ", data_csv[i].hour);
		printf("Minute: %hu ", data_csv[i].minute);
		printf("Temp: %hd\n", data_csv[i].temperature);
	}

}

