
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t num = 0;
uint8_t counter = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		a = a/10;
		num = a%10;
		if (num == 9) counter++;
	}
	(counter == 1)?printf("YES \n"):printf("NO \n");
	
	return 0;
}

