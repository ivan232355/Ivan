/*
D20 ��
�������� � �������
�������� ����������� ������� ���������� ������ ����� n � ������� p.
int recurs_power(int n, int p)
��������� ������ �������, ������ ������.

������ �� �����: 		��� ����� ����� -100 >= n >= 100 � 0 >= p >= 100
������ �� ������: 	���� ����� ����� n � ������� p

������ �1
������ �� �����: 		2 3
������ �� ������: 	8

������ �2
������ �� �����: 		3 4
������ �� ������: 	81
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int n = 0,p = 0;
int power = 0;

int recurs_power(int nn, int pp);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� ��� ����� ����� -100 >= n >= 100 � 0 >= p >= 100\n");
    scanf("%d %d",&n, &p);
	power = recurs_power(n,p);
	printf("%d^%d = %d\n",n,p,power);
	return 0;
}

int recurs_power(int nn, int pp)
{
	if (pp == 0)
	{
		return 1;
	}
	return nn*recurs_power(nn,pp-1);
}
