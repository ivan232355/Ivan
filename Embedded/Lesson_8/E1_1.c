/*
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

Данные на входе: 		5 целых ненулевых чисел через пробел
Данные на выходе: 	Одно число в формате "%.3f"

Пример №1
Данные на входе: 		4 15 3 10 14
Данные на выходе: 	9.200

Пример №2
Данные на входе: 		1 2 3 4 5
Данные на выходе: 	3.000
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a[5];
uint8_t i = 0;


float middle_digits(int arr[]);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("Введите 5 целых ненулевых чисел через пробел\n");
	for (i = 0; i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	middle_digits(a);
	return 0;
}

float middle_digits(int arr[])
{
	int sum = 0;
	float middle = 0;

	for (i = 0; i<5; i++)
	{
		sum+= arr[i];
	}
	middle = (float)sum/5;
	return printf("Среднее арифметическое middle = %.2f\n",middle);
}
