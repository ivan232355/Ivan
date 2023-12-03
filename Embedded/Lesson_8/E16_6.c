/*
E16 Д3 6
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.

Данные на входе: 		10 целых числе через пробел
Данные на выходе: 	Одно число, которое встречается чаще других.

Пример
Данные на входе: 		4 1 2 1 11 2 34 11 0 11
Данные на выходе: 	11
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N  10

int array[N] = {4,1,2,1,11,2,34,11,0,11};
int *sortArray_plus = NULL;
int *sortArray_minus= NULL;
int p = 0;
int k = 0;

void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
}

void sortArr(int array[], int m)
{

    for ( int i = 0; i < m; i++)
    {

    	if (array[i] > 0)
    	{
    		p++;
    		sortArray_plus = (int*)realloc(sortArray_plus, p*sizeof(int));
    		sortArray_plus[p - 1] = array[i];

    	}
    	if (array[i] < 0)
    	{
    		k++;
    		sortArray_minus = (int*)realloc(sortArray_minus, k*sizeof(int));
    		sortArray_minus[k - 1] = array[i];
    	}
    }
}



int main()
{


//    for(int i=0; i < aSize; i++)
//        scanf("%d ", &array[i]);
//    for(int i=0;i<n;i++)

	sortArr(array,N);
    aPrint(sortArray_plus, p);
    free(sortArray_plus);
    aPrint(sortArray_minus, k);
    free(sortArray_minus);
    return 0;
}


