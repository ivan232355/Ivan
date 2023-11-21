/*
D18 ������� 2
����� ����� �������
�������� ����������� ������� � ��������� �� ������ ������. ���������� ����� ���������� ������������ ����� � ������� ����������(����� �������) ����� ������.
void print_digits(int n)
������ �� �����: 		����������� �����
������������������ ���� � ����� ������� ����� ������

������ �1
������ �� �����: 		12345
������ �� ������: 	1 2 3 4 5

������ �2
������ �� �����: 		709
������ �� ������: 	7 0 9
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a = 0;

void print_digits(int n);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� ����������� �����\n");
	scanf("%d",&a);
	print_digits(a);
	return 0;
}

void print_digits(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
    } else
    {
        print_digits(n / 10);
        printf("%d ", n % 10);
    }
}
