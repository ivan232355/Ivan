/*
F2 ДЗ 2
Четные в начало
Написать функцию и программу, демонстрирующую работу данной функции, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])

Данные на входе: 		Функция принимает на вход целые числа
Данные на выходе: 		Отсортированный исходный массив

Пример №1
Данные на входе: 		20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Данные на выходе: 		20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1

Пример №2
Данные на входе: 		1 0 1 0 1
Данные на выходе: 		0 0 1 1 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N  20

int array[N];

void Input(int arr[],int n)
{
int i,num;

    while(scanf("%d",&num)==1)
        array[i++] = num;

}

void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
}

void sort_even_odd(int arr[], uint8_t n)
{
	int sort_arr[n];
	int j = 0;
	for (int i = 0; i<n;i++)
	{

		if (arr[i]%2 == 0)
		{
			sort_arr[j] = arr[i];
			j++;
		}

	}
	for (int i = 0; i<n;i++)
	{

		if (arr[i]%2 != 0)
		{
			sort_arr[j] = arr[i];
			j++;
		}

	}

	for (int i = 0; i<n;i++)
	{
		arr[i] = sort_arr[i];
	}
}



int main()
{
	Input(array,N);
	sort_even_odd(array,N);
	aPrint(array, N);
    return 0;
}




