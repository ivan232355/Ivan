
#include "D:\ECLIPSE_PROJEKT\Emb_Temp\inc\temp_api.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
    int opt = 0;
    int input = 0;
 //   char *input_file = NULL;
//    FILE *file;


    while ((opt = getopt(argc, argv, "hf:a:m:M:y:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Usage: app [-h] [-f input_file] [-a month] [-m Minimum temperature] [-M Maximum temperature] [-y statistics for the year]\n");
            printf("Options:\n");
            printf("-h\t\t Output Help\n");
            printf("-f\t\t Input_file name\n");							 // вывод данных из файла csv
            printf("-a\t\t Average monthly temperature\n");              // среднемесячная температура
            printf("-m\t\t Minimum temperature in the current month\n"); // минимальная температура в текущем месяце
            printf("-M\t\t Maximum temperature in the current month\n"); // максимальная температура в текущем месяце
            printf("-y\t\t Output statistics for the year\n");           // вывод статистики за год
        break;
        case 'f':
        	Open_csv();
        break;
        case 'a':
        	input = atoi(optarg);
        	int Average_temp = Month_Stat_averge(data_csv, input, 16); 				// нахождение средней температуры в указанном месяце
        	printf("Average  temperature in %d monthly = %d\n",input,Average_temp);
        break;
        case 'm':
        	input = atoi(optarg);
        	int Min_temp = Month_Stat_min(data_csv, input, 16); 					// нахождение минимальной температуры в указанном месяце
        	printf("Minimum temperature in the %d month = %d\n",input,Min_temp);
        break;
        case 'M':
        	input = atoi(optarg);
        	int Max_temp = Month_Stat_max(data_csv, input, 16); 					// нахождение максимальной температуры в указанном месяце
        	printf("Maximum temperature in the %d month = %d\n",input,Max_temp);
        break;
        case 'y':
        	input = atoi(optarg);
        	int av_temp;
        	int min_temp;
        	int max_temp;
        	Year_Stat(data_csv, input,&av_temp,&min_temp,&max_temp,16); 			// нахождение среднегодовой температура, минимальной температуры, максимальной температуры
        	printf("Output statistics for the %d year\n",input);
        	printf("----Average  temperature = %d\n",av_temp);
        	printf("----Min  temperature = %d\n",min_temp);
        	printf("----Max  temperature = %d\n",max_temp);
        break;
        case '?':
			printf("Incorrect input.Enter -h to get help \n");
		break;
        }
    }
}
