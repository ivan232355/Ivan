/*
D2 ���� 1
����� ����� �� 1 �� N
��������� ����������� �������, ������� ���������� ����� ���� ����� �� 1 �� N 
������ �� �����: 		���� ����������� ����� 
������ �� ������: 	����� ����� �� 1 �� ���������� ����� 

������ �1
������ �� �����: 		5 
������ �� ������: 	15 

������ �2
������ �� �����: 		100 
������ �� ������: 	5050     
*/

#include <stdio.h>
#include <inttypes.h>

int x = 0; 

int Sum(int a);
		

int main(void)
{
	printf("������� ����� ��������\n");
	scanf("%d \n",&x);
	printf("����� �� 1 �� %d = %d\n", x,Sum(x));		 	
	return 0;
}

int Sum(int a) 
{
	return (a == 1)  ? 1 : a + Sum(a - 1);
}