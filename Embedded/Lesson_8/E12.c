/*
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

Данные на входе: 		10 целых чисел через пробел
Данные на выходе: 	Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.

Пример №1
Данные на входе: 		14 25 13 30 76 58 32 11 41 97
Данные на выходе: 	13 14 25 30 76 97 58 41 32 11

Пример №2
Данные на входе: 		5 4 3 2 1 6 7 8 9 10
Данные на выходе: 	1 2 3 4 5 10 9 8 7 6
 */

#include <stdio.h>
#include <inttypes.h>

#define N  10


void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
}

void sortArray(int array[], int start, int end)
{
    for ( int i = start, j = end - 1; i < j; i++, j--)
    {
    int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

void sortMax_to_Min(int *array, int start, int end)
{
	int i,j,temp;
		for (i = start; i < end; i++)
		{

			for(j = start; j < end; j++)
			{
				if (array[j] < array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}

}
void sortMin_to_Max(int *array, int start, int end)
{
	int i,j,temp;
		for (i = start; i < end; i++)
		{

			for(j = start; j < end; j++)
			{
				if (array[j] > array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}

}

int main()
{

int array[N] = {14,25,13,30,76,58,32,11,41,97};
//    for(int i=0; i < aSize; i++)
//        scanf("%d ", &array[i]);
//    for(int i=0;i<n;i++)
		sortMax_to_Min(array,0,N/2-1);
		sortMin_to_Max(array,N/2,N-1);
        sortArray(array,0,N/2);
        sortArray(array,N/2,N);

    aPrint(array, N);
    return 0;
}
