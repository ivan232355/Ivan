/*
C11 �� 
���
��������� �������, ������� ���������� ���������� ����� �������� ���� ����������� � �������� ������ �� �������������.
int nod(int a, int b)
������ �� �����: 		��� ����� ������������� ����� 
������ �� ������: 	���� ����� ����� - ���������� ����� ��������. 

������ �1
������ �� �����: 		14 21 
������ �� ������: 	7 
*/

#include <stdio.h>
#include <inttypes.h>



int chislo_1 = 0, chislo_2 = 0;

int nod(int a, int b);

int main(void)
{
	
	printf("������� ��� ����� ������������� ����� \n");
	scanf("%d %d \n",&chislo_1,&chislo_2);
	printf("��� = %d \n", nod(chislo_1,chislo_2));	 	
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
