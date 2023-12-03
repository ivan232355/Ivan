/*
E10 ДЗ 3
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

Данные на входе: 		12 целых чисел через пробел
Данные на выходе: 	12 целых чисел через пробел

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 	1 0 5 7 4 -5 3 10 -4 -6 8 -10

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 	9 10 11 12 1 2 3 4 5 6 7 8
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

#define n  12


int a[n];
uint8_t i = 0;


void inv_digits(int arr[],int start, int end);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("Введите %d целых ненулевых чисел через пробел\n",n);
	for (i = 0; i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    inv_digits(a, 0, n/3 - 1); 			// Инверсия первой трети
    inv_digits(a, n/3, 2*n/3 - 1);		// Инверсия второй трети
    inv_digits(a, 2*n/3, n - 1);		// Инверсия третьей трети
	for (i = 0; i<n; i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}

void inv_digits(int arr[],int start, int end)
{
	int inv = 0;

    while (start < end)
    {
        inv = arr[start];
        arr[start] = arr[end];
        arr[end] = inv;
        start++;
        end--;
    }

}
