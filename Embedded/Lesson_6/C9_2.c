/*
C9 Практ 2
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 		Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

Пример №1
Данные на входе: 		5 
Данные на выходе: 	120 
*/

#include <stdio.h>
#include <inttypes.h>

uint8_t a = 0;

uint64_t factorial(int n);

int main(void)
{
	printf("Введите целое положительное число не больше 20 \n");
	scanf("%hhd \n",&a);
	printf("%"PRIu64"", factorial(a));	 	
	return 0;
}

uint64_t factorial(int n) 
{
	uint16_t i = 0;
	uint64_t result = 1;
	
	for (i = 1; i <= n;i++)
	{
		result*=i;
	}
	return result;
}
