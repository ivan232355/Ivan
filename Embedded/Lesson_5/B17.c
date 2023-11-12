
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t i = 0;
uint16_t num = 0;
uint16_t sum = 0;
uint16_t product = 1;

int main(void)
{
	printf("Введите целое положительное число \n");
	scanf("%hd \n",&a);
	
	for (i=10; i<=a; i++)
	{	
		num = i;
		sum = 0;
		product = 1;
		while(num!=0)
		{
			uint16_t digit = num%10;
			sum+=digit;
			product*=digit;
			num/=10;
		}
	if (sum == product) printf("Числа от 10 до %d, у которых сумма цифр равна произведению цифр %d:\n", a,i);
	}	 
	
	
	return 0;
}

