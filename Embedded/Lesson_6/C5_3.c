/*
C5 �� 
����� �� 1 �� N
��������� �������, ������� ���������� ����� ���� ����� �� 1 �� N � �������� ������ �� �������������. 

������ �1
������ �� �����: 		���� ����� ������������� ����� N 
������ �� ������: 	����� ����� - ����� ����� �� 1 �� N 

������ �2
������ �� �����: 		100 
������ �� ������: 	5050 
*/

#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;

uint16_t Sum(uint16_t b);

int main(void)
{
	printf("������� ���� ����� ������������� ����� \n");
	scanf("%hd \n",&a);
	printf("%d ", Sum(a));	 	
	return 0;
}

uint16_t Sum(uint16_t b) 
{
	uint16_t i = 0;
	uint16_t result = 0;
	
	for(i=0; i<=a;i++)
	{
		result+=i;
	}
	return result;
}
