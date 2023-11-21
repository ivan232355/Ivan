/*
D8 �� 2
�� A �� B
��������� ����������� �������, �������� ��� ����� �� A �� B ������������, � ������� �����������, ���� A < B, ��� � ������� �������� � ��������� ������.

������ �� �����: 		��� ����� ����� ����� ������. 
������ �� ������: 	������������������ ����� �����. 

������ �1
������ �� �����: 		5 2 
������ �� ������: 	5 4 3 2 

������ �2
������ �� �����: 		2 7 
������ �� ������: 	2 3 4 5 6 7     
*/

#include <stdio.h>
#include <inttypes.h>

int a = 0,b = 0; 
uint8_t dir = 0;
void print_num(int aa, int bb, uint8_t direction);
		
int main(void)
{
	printf("������� ��� ����� ����� ����� ������\n");
	scanf("%d %d",&a,&b);
	(a<b) ? (dir = 1) : (dir = 0);
	print_num(a,b,dir);
	
	return 0;
}

void print_num(int aa, int bb, uint8_t direction) 
{
	if (direction == 1)
	{
		if (aa <= bb)
		{
			printf("%d ",aa);
			print_num(aa+1,bb,dir);
		}
		else
		{
			return;
		}
	}
	else 
	{
		if (aa >= bb)
		{
			printf("%d ",aa);
			print_num(aa-1,bb,dir);
		}
		else
		{
			return;
		}
	}
}
