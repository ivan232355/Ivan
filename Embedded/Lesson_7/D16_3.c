/*
D16 ������� 3
������ ������� ������
�������� ���������� ����������� ������� � ��������� �� ���������� �������� �� ��������� ����������� ����� ������ �������� ������.
int is2pow(int n)
������ �� �����: 		���� ����������� �����. 
������ �� ������: 	YES ��� NO 

������ �1
������ �� �����: 		8 
������ �� ������: 	YES 

������ �2
������ �� �����: 		7 
������ �� ������: 	NO    
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a = 0,i = 0; 

int is2pow(int n);
		
int main(void)
{
	setlocale(LC_ALL, "");
	printf("������� ���� ����������� �����\n");
    scanf("%d",&a);
	is2pow(a);
	return 0;
}

int is2pow(int n)
{
	if (n==1)
	{
		printf("NO");
		return 1;	
	}
	if (n%2 == 0 || n ==0)
	{
		printf("YES");
		return 0;
	}
	else
	{
		is2pow(n/2);	
	}
}
