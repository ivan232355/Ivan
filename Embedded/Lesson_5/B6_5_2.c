
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t b_1 = 0;
uint16_t b_2 = 0;
uint8_t flag = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		b_1 = a%10; //4
		b_2 = a%100; //34
		b_2 = b_2/10;
		a = a/10;
		if (b_1 == b_2) flag =1;
	}
	(flag == 1) ? printf("YES \n") : printf("NO \n");
	
	return 0;
}

