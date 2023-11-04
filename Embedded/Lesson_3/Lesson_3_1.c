
#include <stdio.h>


long a = 0,b = 0,c = 0;
long sum = 0;

int main(void)
{
	printf("Введите три целых числа через пробел, q для завершения\n");
	scanf("%ld %ld %ld\n",&a,&b,&c);
	sum = a + b + c;
	printf("%ld + %ld + %ld = %ld\n",a,b,c,sum);
	return 0;
}

