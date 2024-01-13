#include "temp_api.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int opt = 0;
	int input = 0;
	struct Temp_Data *data_csv;		// Объявляем указатель на массив структур
	int num_records; 			// Переменная для хранения количества записей
	uint8_t flag_error = 1;

	while ((opt = getopt(argc, argv, "hf:a:m:M:y:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			printf("Usage: app [-h] [-f input_file] [-a month] [-m Minimum temperature] [-M Maximum temperature] [-y statistics for the year]\n");
			printf("Options:\n");
			printf("-h\t\t Output Help\n");
			printf("-f\t\t Input_file name\n");		// вывод данных из файла csv
			printf("-a\t\t Average monthly temperature\n"); // среднемесячная температура
			printf("-m\t\t Minimum temperature in the current month\n"); // минимальная температура в текущем месяце
			printf("-M\t\t Maximum temperature in the current month\n"); // максимальная температура в текущем месяце
			printf("-y\t\t Output statistics for the year\n"); // вывод статистики за год
		break;
		case 'f':
			if (Open_csv(&data_csv,&num_records) == 1)
			{
				printf("OK....\n");
			}
			else
			{
				flag_error = 0;
			}
		break;
		case 'a':
			if (flag_error == 1)
			{
			input = atoi(optarg);
			double Average_temp = Month_Stat_averge(data_csv, input, num_records); // нахождение средней температуры в указанном месяце
			printf("Average  temperature in %d monthly = %.1f\n", input,
					Average_temp);
			}
			else
			{
				//free(data_csv);
				printf("ERROR.Incorrect input data\n");
			}
		break;
		case 'm':
			if (flag_error == 1)
			{
			input = atoi(optarg);
			int Min_temp = Month_Stat_min(data_csv, input, num_records); // нахождение минимальной температуры в указанном месяце
			printf("Minimum temperature in the %d month = %d\n", input,
					Min_temp);
			}
			else
			{
				//free(data_csv);
				printf("ERROR.Incorrect input data\n");
			}
		break;
		case 'M':
			if (flag_error)
			{
			input = atoi(optarg);
			int Max_temp = Month_Stat_max(data_csv, input, num_records); // нахождение максимальной температуры в указанном месяце
			printf("Maximum temperature in the %d month = %d\n", input,
					Max_temp);
			}
			else
			{
				//free(data_csv);
				printf("ERROR.Incorrect input data\n");
			}

		break;
		case 'y':
			if (flag_error)
			{
			input = atoi(optarg);
			int av_temp;
			int min_temp;
			int max_temp;
			Year_Stat(data_csv, input, &av_temp, &min_temp, &max_temp, num_records); // нахождение среднегодовой температура, минимальной температуры, максимальной температуры
			printf("Output statistics for the %d year\n", input);
			printf("----Average  temperature = %d\n", av_temp);
			printf("----Min  temperature = %d\n", min_temp);
			printf("----Max  temperature = %d\n", max_temp);
			}
			else
			{
				//free(data_csv);
				printf("ERROR.Incorrect input data\n");
			}
		break;
		case '?':
			printf("Incorrect input.Enter -h to get help \n");
		break;
		}
	}
	free(data_csv);
}
