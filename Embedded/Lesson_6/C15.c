/*
C15 ����� 
����� �� �����������

��������� ������� ���������� �������, ������� ����������, ����� ��, ��� � �������� ����� ��� ����� ����� �� �����������. ��������� ������ ������� ������ ������.

int grow_up(int n)

������ �� �����: 		���� ����� �� ������������� ����� 
������ �� ������: 	YES ��� NO 

������ �1
������ �� �����: 		258 
������ �� ������: 	YES 

������ �2
������ �� �����: 		528 
������ �� ������: 	NO   
*/

#include <stdio.h>
#include <inttypes.h>


int x = 0;

int grow_up(int n);

int main(void)
{
	printf("������� ���� ����� �� ������������� �����\n");
	scanf("%d \n",&x);
	int result = grow_up(x);
	(result == 1) ? printf("YES\n") : printf("NO\n");		 	
	return 0;
}

int grow_up(int n) 
{
    int flag = 1;
    while (n!=0)
    {
		
		if (n%10<=(n/10)%10)
		{
			flag = 0;
		}		
		n=n/10;
	}
    return flag;
}

