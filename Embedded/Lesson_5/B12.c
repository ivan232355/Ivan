
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t b = 0;
uint16_t max = 0;
uint16_t min = 9;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		b = a%10;	
		if (b > max) max = b;
		if (b < min) min = b;
		a= a/10;
	}	 
	printf("%d %d\n",min,max);
	
	return 0;
}

