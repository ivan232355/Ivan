/*
D19 �� 6
������� ��� ����������� ������ a
���� ������ �� ���������� ��������, �������� � ������ ����������. � ����� ������ ������ �����. ���������� ����������� ����������� �������, ������� ��������� ������ ������ �� ������������ ������ ����� � ���������� ����� ����� - ���������� �������� 'a' � ������ ������.
int acounter(void)
��������� ������ ������� ������ ������.

������ �� �����: 		������ ��������� �� ���������� ����, �������� � ������ ����������. � ���� ������ ������ '.'
������ �� ������: 	���� ����� �����.

������ �1
������ �� �����: 		abcd a.
������ �� ������: 	2

������ �2
������ �� �����: 		Hello world.
������ �� ������: 	0
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int n = 0,p = 0;
char str = 0;

int acounter(void);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� ������ ��������� �� ���������� ����, �������� � ������ ����������. � ���� ������ ������ '.'\n");
	printf("%d\n",acounter());
	return 0;
}

int acounter(void)
{
	int counter = 0;
	char c ;
	scanf("%c",&c);
	if (c == '.')
		return counter;
	if (c == 'a')
		counter ++;

    counter += acounter();
    return counter;
}
