
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t b = 0;
uint8_t even = 0;
uint8_t odd = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		b = a%10;	
		b%2 == 0 ? even++ : odd++;
		a= a/10;
	}	 
	printf("%d %d\n",even,odd);
	
	return 0;
}

