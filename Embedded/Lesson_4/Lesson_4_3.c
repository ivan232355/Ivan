
#include <stdio.h>

long p = 0;
long a = 0, b = 0, c = 0;
long max = 0;


int main(void)
{
	printf("Введите трехзначное целое число\n");
	scanf("%ld\n",&p);
	a = (long)p%10;
	b = (long)p%100/10;
	c = (long)p/100;
	if (a>b && a>c) max = a;
	if (b>a && b>c) max = b;
	if (c>a && c>b) max = c;
	printf("%ld\n",max);	
	
	return 0;
}

