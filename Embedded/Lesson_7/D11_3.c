/*
D11 �� 3
���������� 1
���� ����������� ����� N. ��������� ���������� �1� � �������� ������ �����. 
������ �� �����: 		����������� ����� 
������ �� ������: 	����� ����� - ���������� ������ � �������� ������ �����. 

������ �1
������ �� �����: 		5 
������ �� ������: 	2 

������ �2
������ �� �����: 		255 
������ �� ������: 	8     
*/

#include <stdio.h>
#include <inttypes.h>

int a = 0,counter = 0; 

int binary_counter(int aa);
		
int main(void)
{
	printf("������� ��� ����� ����� ����� ������\n");
	scanf("%d",&a);
	counter = binary_counter(a);
	printf("���������� ������ � �������� ������ ����� %d: %d\n", a, counter);
	return 0;
}

int binary_counter(int aa) 
{
	if (aa == 0)
    {
        return 0;
    }
    else
    {
        return (aa % 2) + binary_counter(aa / 2);
    }
}
