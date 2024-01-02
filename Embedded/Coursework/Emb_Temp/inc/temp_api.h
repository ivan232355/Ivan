#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

struct Temp_Data
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};


double Month_Stat_averge(struct Temp_Data* data, int target_month,int size); 	//среднемесячная температура
int Month_Stat_min (struct Temp_Data *data, int target_month,int size); 		//минимальная температура в текущем месяце
int Month_Stat_max (struct Temp_Data *data, int target_month,int size);		//максимальная температура в текущем месяце
void Year_Stat (struct Temp_Data *data,int target_year, int* avTemp, int* minTemp, int* maxTemp,int size);				//вывод статистики за год
void GetData_csv(FILE *file, struct Temp_Data *data, int records);			//получение данных из файла
int Open_csv (struct Temp_Data **data, int *records);						//функция открытия файла
int Checking_data(struct Temp_Data *data, int records);					// функция проверки корректности данных

#endif
