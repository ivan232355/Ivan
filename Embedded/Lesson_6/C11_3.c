/*
C11 �� 
���
���⠢��� �㭪��, ����� ��।���� �������訩 ��騩 ����⥫� ���� ����ࠫ��� � �ਢ��� �ਬ�� �� �ᯮ�짮�����.
int nod(int a, int b)
����� �� �室�: 		��� 楫�� ������⥫��� �᫠ 
����� �� ��室�: 	���� 楫�� �᫮ - �������訩 ��騩 ����⥫�. 

�ਬ�� �1
����� �� �室�: 		14 21 
����� �� ��室�: 	7  
*/

#include <stdio.h>
#include <inttypes.h>



int chislo_1 = 0, chislo_2 = 0;

int nod(int a, int b);

int main(void)
{
	
	printf("������ ��� 楫�� ������⥫��� �᫠ \n");
	scanf("%d %d \n",&chislo_1,&chislo_2);
	printf("%d \n", nod(chislo_1,chislo_2));	 	
	return 0;
}

int nod(int a, int b) 
{
    while (a != b)
    {
        (a > b) ? (a = a - b) : (b = b - a);
    }
	return a;
}
