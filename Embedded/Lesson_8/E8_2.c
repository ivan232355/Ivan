/*
E8 ���� 2
�������� ������ �����
������� ������ �� 12 ��������� � ��������� �������� ��� ������ ����� �������.

������ �� �����: 		12 ����� ����� ����� ������
������ �� ������: 	12 ����� ����� ����� ������

������ �1
������ �� �����: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
������ �� ������: 	10 3 -5 4 -10 8 -6 -4 7 5 0 1

������ �2
������ �� �����: 		1 2 3 4 5 6 7 8 9 10 11 12
������ �� ������: 	4 3 2 1 8 7 6 5 12 11 10 9
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
	printf("������� %d ����� ��������� ����� ����� ������\n",n);
	for (i = 0; i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    inv_digits(a, 0, n/3 - 1); 		// �������� ������ �����
    inv_digits(a, n/3, 2*n/3 - 1);	// �������� ������ �����
    inv_digits(a, 2*n/3, n - 1);		// �������� ������� �����
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
