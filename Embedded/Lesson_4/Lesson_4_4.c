
#include <stdio.h>
#include <inttypes.h>


long a[5];
long max = 0;
long min = 0;

uint8_t i = 0 ;

int main(void)
{
	printf("¬ведите п€ть целый чисел через пробел\n");
	scanf("%ld %ld %ld %ld %ld\n",&a[0],&a[1],&a[2],&a[3],&a[4]);
	max = a[0];
	min = a[5];
	for (i = 1;i < 5;i++)
	{	
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	printf("%ld\n",max + min);
	return 0;
}

