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

extern struct Temp_Data data_csv[16];

int Month_Stat_averge(struct Temp_Data data[], int target_month,uint8_t size); 	//среднемесячная температура
int Month_Stat_min (struct Temp_Data data[], int target_month,uint8_t size); 		//минимальная температура в текущем месяце
int Month_Stat_max (struct Temp_Data data[], int target_month,uint8_t size);		//максимальная температура в текущем месяце
void Year_Stat (struct Temp_Data data[],int target_year, int* avTemp, int* minTemp, int* maxTemp,uint8_t size);				//вывод статистики за год
void GetData_csv(FILE*file);										//получение данных из файла
int Open_csv(void);											//функция открытия файла

#endif
