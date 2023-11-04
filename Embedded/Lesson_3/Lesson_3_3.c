
#include <stdio.h>


long a = 0,b = 0;
long diff = 0;

int main(void)
{
	printf("Введите два целых целых числа через пробел и q для завершения\n");
	scanf("%ld %ld\n",&a,&b);
	diff = a - b;
	printf("%ld\n",diff);
	return 0;
}

