/*
 ============================================================================
 Name        : 11.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 Необходимо реализовать только одну функцию, которой на входе передаётся вещественное число в типе float,
 она возвращает порядок который хранится в поле EXP в виде десятичного целого числа.
Функция должна строго соответствовать прототипу int extractExp(float)
Вставьте только текст функции int extractExp(float)
Пример №1
Данные на входе:		1.0
Данные на выходе:	127
Пример №2
Данные на входе:		2.0
Данные на выходе:	128
Пример №3
Данные на входе:		3.99999
Данные на выходе:	128
Пример №4
Данные на входе:		0.001
Данные на выходе:	117
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int extractExp(float f)
{
	union
	{
		float f;
		struct
		{
			uint32_t mantissa :23;
			uint32_t exp :8;
			uint32_t s :1;
		} field;
	} fl;

	fl.f = f;
	return fl.field.exp;
}



int main(void)
{
    float num = 1.0;
    int exp = extractExp(num);
    printf("Exponent: %d\n", exp); // Выводит экспоненту в виде целого числа
    return 0;
}
