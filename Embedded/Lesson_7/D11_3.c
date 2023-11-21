/*
D11 ДЗ 3
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 		Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 		5 
Данные на выходе: 	2 

Пример №2
Данные на входе: 		255 
Данные на выходе: 	8     
*/

#include <stdio.h>
#include <inttypes.h>

int a = 0,counter = 0; 

int binary_counter(int aa);
		
int main(void)
{
	printf("Введите два целых числа через пробел\n");
	scanf("%d",&a);
	counter = binary_counter(a);
	printf("Количество единиц в двоичной записи числа %d: %d\n", a, counter);
	return 0;
}

int binary_counter(int aa) 
{
	if (aa == 0)
    {
        return 0;
    }
    else
    {
        return (aa % 2) + binary_counter(aa / 2);
    }
}
