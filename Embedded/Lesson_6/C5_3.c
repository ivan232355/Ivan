/*
C5 �� 
�㬬� �� 1 �� N
���⠢��� �㭪��, ����� ��।���� �㬬� ��� �ᥫ �� 1 �� N � �ਢ��� �ਬ�� �� �ᯮ�짮�����. 

�ਬ�� �1
����� �� �室�: 		���� 楫�� ������⥫쭮� �᫮ N 
����� �� ��室�: 	����� �᫮ - �㬬� �ᥫ �� 1 �� N 

�ਬ�� �2
����� �� �室�: 		100 
����� �� ��室�: 	5050 
*/

#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;

uint16_t Sum(uint16_t b);

int main(void)
{
	printf("������ 楫�� ������⥫쭮� �᫮ \n");
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
