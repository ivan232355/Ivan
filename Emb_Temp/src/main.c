
#include "E:\eclipse-workspace\Emb_Temp\inc\temp_api.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt = 0;
    char *input_file = NULL;
    FILE *file;

    while ((opt = getopt(argc, argv, "hf:a:m:M:y:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Usage: app [-h] [-f input_file] [-a month] [-m Minimum temperature] [-M Maximum temperature] [-y statistics for the year]\n");
            printf("Options:\n");
            printf("-h\t\t Output Help\n");
            printf("-f\t\t Input_file name\n");
            printf("-a\t\t Average monthly temperature\n");              // среднемесячная температура
            printf("-m\t\t Minimum temperature in the current month\n"); // минимальная температура в текущем месяце
            printf("-M\t\t Maximum temperature in the current month\n"); // максимальная температура в текущем месяце
            printf("-y\t\t Output statistics for the year\n");           // вывод статистики за год
            break;
        case 'f':
            printf("Input file: %s\n", optarg);
            input_file = optarg;
            if (input_file == NULL)
            {
                printf("No input file!\n");
                return 1;
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
            
            break;
        case 'a':
            break;
        }
    }
}
