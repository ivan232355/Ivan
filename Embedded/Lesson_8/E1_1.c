/*
������� �������������� �����
������ c ���������� ������ �� 5 ���������, ����� ������� �������������� ���� ��������� �������.

������ �� �����: 		5 ����� ��������� ����� ����� ������
������ �� ������: 	���� ����� � ������� "%.3f"

������ �1
������ �� �����: 		4 15 3 10 14
������ �� ������: 	9.200

������ �2
������ �� �����: 		1 2 3 4 5
������ �� ������: 	3.000
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a[5];
uint8_t i = 0;


float middle_digits(int arr[]);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� 5 ����� ��������� ����� ����� ������\n");
	for (i = 0; i<5;i++)
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

	for (i = 0; i<5; i++)
	{
		sum+= arr[i];
	}
	middle = (float)sum/5;
	return printf("������� �������������� middle = %.2f\n",middle);
}
