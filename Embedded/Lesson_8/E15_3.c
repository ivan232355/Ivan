/*
E15 Практик 3
Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

Данные на входе: 		10 целых чисел через пробел.
Данные на выходе: 	Сперва положительные числа, потом отрицательыне числа, через пробел.

Пример
Данные на входе: 		5 -4 0 1 4 -3 -3 3 0 2
Данные на выходе: 		5 1 4 3 2 -4 -3 -3
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N  10

int array[N] = {5,-4,0,1,4,-3,-3,3,0,2};
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


