
#include <stdio.h>


long a = 0;
long diff = 0;

int main(void)
{
	printf("������ 楫�� ��姭�筮� �᫮ � q ��� �����襭��\n");
	scanf("%ld\n",&a);
	diff = (long)a%10;
	diff *= (long)a%100/10;
	diff *= (long)a/100;
	printf("%ld\n",diff);
	return 0;
}

