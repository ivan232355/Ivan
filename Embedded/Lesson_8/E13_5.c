/*
E13 �� 5
������ � ����� ����
������� ������ �� 10 ��������� � �������� � ������ ������ ��� �����, � ������� ������ � ����� ����� (����� ��������) � ����.

������ �� �����: 		10 ����� ����� ����� ������.
������ �� ������: 	����� ����� ����� ������, � ������� ������ � ����� ����� - ����

������
������ �� �����: 		40 105 203 1 14 1000 22 33 44 55
������ �� ������: 	105 203 1 1000
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
