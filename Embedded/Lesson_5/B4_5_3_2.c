
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint8_t counter = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		counter++;	
		a = a/10;
	}
	(counter==3) ? printf("YES \n") : printf("NO \n");
	
	return 0;
}

