
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t num = 0;
uint8_t flag = 0;
uint8_t counter = 0;
uint8_t i = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		num = a%10;
		a = a/10;
		counter++;
		if (num%2 == 0) flag++;
	}	 
	(flag == counter)?printf("YES \n"):printf("NO \n");
	
	return 0;
}

