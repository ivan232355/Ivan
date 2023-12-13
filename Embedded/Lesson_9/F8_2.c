/*
F8 ����� 2
����������� �����
�������� ������� � ���������, ��������������� ������ ������ �������.
� ������������������ �������� ����� ����� �� M �� N ( M ������ N, M ������ ��� ����� 1) � ������������ �������, �� ���� �� ����� ���������
(��������� ����������� ����� �� ������ ����). N �� ����������� 1000. ������������������ ������������� ������ 0. ���������� ����������� �����.

������ �� �����: 		������������������ ����� ����� �� M �� N. M, N �� ����������� 1000.
������ �� ������: 	���� ����� �����

������ �1
������ �� �����: 		2 3 1 4 7 6 9 8 10 0
������ �� ������: 	5

������ �2
������ �� �����: 		41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
������ �� ������: 	35
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int s[100];
int size;
int number = 0;

void find_sum_max_min(int arr[], int size, int *max, int *min, int* sum)
{
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        else if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
    printf("min = %d\n",*min);
    printf("max = %d\n",*max);
	for (int i = *min; i < *max; i++)
    {
        sum += 1;
    }
	printf("sum = %d\n",*sum);
}

int find_number(int arr[], int size)
{
    int sum = 0;
    int start_arr = 0 , end_arr = 0;
    int sum_max_arr = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

	find_sum_max_min(arr, size,&end_arr, &start_arr,&sum_max_arr);
	printf("sum_max_arr = %d\n",sum_max_arr);
    return sum_max_arr - sum;
}


int is_two_same(int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int checking_number(int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
		if (a[i] > 1000)
		{
          printf(">1000!!!\n");
		return 0;
		}
    }
    return 1;
}

int isDigit(char c)
{
    return ((c>='0')&&(c<='9'));
}

int InputGet(int arr[], int n)
{
int i;
char c;
    while((c=getchar())!='\n')
    {
        if(isDigit(c))
        {
            int number=0;
            do
            {
                number=number*10+c-'0';
                c=getchar();
            }
            while(isDigit(c));
            arr[i++] = number;
            if(c=='\n')
                break;
        }
    }
    return i;
}



int main()
{
    size = InputGet(s, 100);

    if (!checking_number(size, s)) 		// ���������, ��� ��� ����� � ������� ������ ��� ����� 1000
    {
        return 1;
    }

    if (is_two_same(size,s) == 1) 		// ���������, ���� �� ���������� ����� � �������
    {
        printf("ERROR\n"); 				// ���� ����, ������� ���������
    }
    else
    {
        number = find_number(s,size); 	// ������� ����������� �����
        printf("%d",number); 			// ������� ���
    }
    return 0;
}




