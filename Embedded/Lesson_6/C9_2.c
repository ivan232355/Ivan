/*
C9 ����� 2
���������
��������� ������� ���������� N!. ������������ �� ��� ���������� ����������
int factorial(int n)

������ �� �����: 		����� ������������� ����� �� ������ 20 
������ �� ������: 	����� ������������� ����� 

������ �1
������ �� �����: 		5 
������ �� ������: 	120 
*/

#include <stdio.h>
#include <inttypes.h>

uint8_t a = 0;

uint64_t factorial(int n);

int main(void)
{
	printf("������� ����� ������������� ����� �� ������ 20 \n");
	scanf("%hhd \n",&a);
	printf("%"PRIu64"", factorial(a));	 	
	return 0;
}

uint64_t factorial(int n) 
{
	uint16_t i = 0;
	uint64_t result = 1;
	
	for (i = 1; i <= n;i++)
	{
		result*=i;
	}
	return result;
}
