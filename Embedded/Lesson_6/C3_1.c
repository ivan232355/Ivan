/*C3 �ࠪ� 1
�।��� ��䬥��᪮� �ᥫ
������� �㭪��, ����� �����頥� �।��� ��䬥��᪮� ���� ��।����� �� ��㬥�⮢ (��ࠬ��஢).
int middle(int a, int b)
����� �� �室�: 		��� 楫�� �� ����⥫��� �᫠ 
����� �� ��室�: 	���� 楫�� �᫮ 

�ਬ�� �1
����� �� �室�: 		5 7 
����� �� ��室�: 	6 

�ਬ�� �2
����� �� �室�: 		10 20 
����� �� ��室�: 	15 
*/

#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0, b = 0;
uint16_t result = 0;

int middle(int a, int b);

int main(void)
{
	printf("������ ��� 楫�� ������⥫��� �᫠ \n");
	scanf("%hd %hd \n",&a,&b);
	printf("%d ", middle(a,b));	 	
	return 0;
}

int middle(int a, int b) 
{
	return (a+b)/2;
}
