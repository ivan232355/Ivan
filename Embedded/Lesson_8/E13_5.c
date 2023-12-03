/*
E13 ДЗ 5
Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

Данные на входе: 		10 целых чисел через пробел.
Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль

Пример
Данные на входе: 		40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 	105 203 1 1000
 */

#include <stdio.h>
#include <inttypes.h>

#define N  10

int array[N] = {40,105,203,1,14,1000,22,33,44,55};
int sortArray[] = {0,};


void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
}

void sortZero(int array[], int m)
{
	int j = 0;
    for ( int i = 0; i < m; i++)
    {
    int t = array[i];
    	t/=10;
    	if (t%10 == 0)
    	{
    		sortArray[j] = array[i];
    		j++;
    	}
    }
}



int main()
{


	for(int i=0; i < N; i++)
	{
        scanf("%d ", &array[i]);
	}
	sortZero(array,N);
    aPrint(sortArray, sizeof(sortArray));
    return 0;
}
