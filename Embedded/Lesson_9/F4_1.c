/*
F4 ����� 1
����� � ������
�������� ������� � ���������, ��������������� ������ ������ �������.
������� � ������� ����������� �����, �������� � ������. ����� - ����������. ������� ������ ������ ��������������� ���������:

void print_digit(char s[])

������ �� �����: 		������ �� ���������� ����, ��������, ������ ���������� � ����
������ �� ������: 	������� ������ ��������� �� ���� ������ � �������� �� ������ �� �������: ����� ������ ����������.

������
������ �� �����: 		Hello123 world77.
������ �� ������: 	1 1 2 1 3 1 7 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char s[10];


void input(void)
{
int i = 0;
char c;

    while( (c=getchar())!='\n' )
        s[i++]=c;
    s[i]='\0';

}


void print_digit(char s[])
{
	int count[10] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            count[s[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] > 0)
        {
            printf("%d %d ", i, count[i]);
        }
    }
}


int main()
{
	input();
	print_digit(s);
    return 0;
}




