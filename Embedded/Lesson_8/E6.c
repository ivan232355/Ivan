/*
E6
������� �������������� �������
������� ������ �� 12 ��������� � ���������� ������� �������������� ��������� �������.

������ �� �����: 		12 ����� ����� ����� ������
������ �� ������: 	������� �������������� � ������� "%.2f"

������ �1
������ �� �����: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
������ �� ������: 	1.08

������ �2
������ �� �����: 		1 2 3 4 5 6 7 8 9 10 11 12
������ �� ������: 	6.50
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

#define n  12


int a[n];
uint8_t i = 0;


float middle_digits(int arr[]);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� %d ����� ��������� ����� ����� ������\n",n);
	for (i = 0; i<n;i++)
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

	for (i = 0; i<n; i++)
	{
		sum+= arr[i];
	}
	middle = (float)sum/n;
	return printf("������� �������������� middle = %.2f\n",middle);
}
