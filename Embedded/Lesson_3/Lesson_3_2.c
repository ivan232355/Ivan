
#include <stdio.h>


long a = 0,b = 0,c = 0;
long sum = 0;
long works = 0;

int main(void)
{
	printf("������ �� 楫�� �᫠ �१ �஡��, q ��� �����襭��\n");
	scanf("%ld %ld %ld\n",&a,&b,&c);
	sum = a + b + c;
	works = a*b*c;
	printf("%ld + %ld + %ld = %ld\n",a,b,c,sum);
	printf("%ld * %ld * %ld = %ld\n",a,b,c,works);
	return 0;
}

