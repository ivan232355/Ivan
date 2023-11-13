/*
C5 ДЗ 
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

Пример №1
Данные на входе: 		Одно целое положительное число N 
Данные на выходе: 	Целое число - сумма чисел от 1 до N 

Пример №2
Данные на входе: 		100 
Данные на выходе: 	5050 
*/

#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;

uint16_t Sum(uint16_t b);

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	printf("%d ", Sum(a));	 	
	return 0;
}

uint16_t Sum(uint16_t b) 
{
	uint16_t i = 0;
	uint16_t result = 0;
	
	for(i=0; i<=a;i++)
	{
		result+=i;
	}
	return result;
}
