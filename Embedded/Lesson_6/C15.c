/*
C15 �ࠪ� 
����� �� �����⠭��

���⠢��� �㭪�� �������� �㭪��, ����� ��।����, ��୮ ��, �� � �������� �᫥ �� ���� ���� �� �����⠭��. �ᯮ���� ������ �㭪�� ���� ������.

int grow_up(int n)

����� �� �室�: 		���� 楫�� �� ����⥫쭮� �᫮ 
����� �� ��室�: 	YES ��� NO 

�ਬ�� �1
����� �� �室�: 		258 
����� �� ��室�: 	YES 

�ਬ�� �2
����� �� �室�: 		528 
����� �� ��室�: 	NO    
*/

#include <stdio.h>
#include <inttypes.h>


int x = 0;

int grow_up(int n);

int main(void)
{
	printf("������ 楫�� �᫮ \n");
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

