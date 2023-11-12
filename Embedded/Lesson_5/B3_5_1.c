
#include <stdio.h>
#include <inttypes.h>

uint16_t a = 0;
uint16_t b = 0;
uint8_t i = 0;
uint32_t sum = 0;

int main(void)
{
	printf("Введите два целых числа по модулю не больше 100 \n");
	scanf("%hu %hu \n",&a,&b);
	
	if (a>100 || b>100)
	{
		printf("Ошибка ввода, число больше 100 \n");
		return 0;
	}
	
	for (i=a; i<=b; i++)
	{
		sum+=i*i;
	}
	printf("%d ", sum);
	
	return 0;
}

