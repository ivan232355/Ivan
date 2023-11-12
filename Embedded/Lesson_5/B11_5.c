
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t num = 0;
uint16_t reverse = 0;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	while (a!=0)
	{
		num = a%10;
		reverse = reverse*10 + num;
		a= a/10;
	}	 
	printf("%d\n",reverse);
	
	return 0;
}

