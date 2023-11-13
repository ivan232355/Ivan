/*
C17 ��
����� ���� ����� ������������

��������� ���������� �������, ������� ����������, ����� ��, ��� � ������ ����� ����� ���� ����� ������������.

int is_happy_number(int n)

������ �� �����: 		����� �� ������������� ����� 
������ �� ������: 	YES ��� NO 

������ �1
������ �� �����: 		123 
������ �� ������: 	YES 

������ �2
������ �� �����: 		528 
������ �� ������: 	NO   
*/

#include <stdio.h>
#include <inttypes.h>


int x = 0;

int is_happy_number(int n);

int main(void)
{
	printf("������� ����� �� ������������� ����� \n");
	scanf("%d \n",&x);
	int result = is_happy_number(x);
	(result == 1) ? printf("YES\n") : printf("NO\n");		 	
	return 0;
}

int is_happy_number(int n) 
{
    int flag = 0;
    uint16_t sum = 0;
    uint16_t multiply = 1;
    while (n!=0)
    {
		sum+=n%10;
		multiply*=n%10;
		n=n/10;
	}
	if (sum == multiply)
	{
		flag = 1;
	}
    return flag;
}

