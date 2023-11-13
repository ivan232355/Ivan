/*
C17 ДЗ
Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 		Целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		123 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		528 
Данные на выходе: 	NO    
*/

#include <stdio.h>
#include <inttypes.h>


int x = 0;

int is_happy_number(int n);

int main(void)
{
	printf("Введите целое число \n");
	scanf("%d \n",&x);
	int result = is_happy_number(x);
	(result == 1) ? printf("YES\n") : printf("NO\n");		 	
	return 0;
}

int is_happy_number(int n) 
{
    int flag = 0;
    uint16_t sum = 0;
    uint16_t multiply = 1;
    while (n!=0)
    {
		sum+=n%10;
		multiply*=n%10;
		n=n/10;
	}
	if (sum == multiply)
	{
		flag = 1;
	}
    return flag;
}

