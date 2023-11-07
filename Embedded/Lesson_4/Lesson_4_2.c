
#include <stdio.h>


long a = 0, b = 0, c = 0;
long max = 0;


int main(void)
{
	printf("Введите три целый числа\n");
	scanf("%ld %ld %ld\n",&a,&b,&c);
	if (a>b && a>c) max = a;
	if (b>a && b>c) max = b;
	if (c>a && c>b) max = c;
	printf("%ld\n",max);	
	
	return 0;
}

