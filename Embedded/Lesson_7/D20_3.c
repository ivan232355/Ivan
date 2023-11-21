/*
D20 ДЗ
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 		Два целых числа -100 >= n >= 100 и 0 >= p >= 100
Данные на выходе: 	Одно целое число n в степени p

Пример №1
Данные на входе: 		2 3
Данные на выходе: 	8

Пример №2
Данные на входе: 		3 4
Данные на выходе: 	81
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int n = 0,p = 0;
int power = 0;

int recurs_power(int nn, int pp);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("Введите два целых числа -100 >= n >= 100 и 0 >= p >= 100\n");
    scanf("%d %d",&n, &p);
	power = recurs_power(n,p);
	printf("%d^%d = %d\n",n,p,power);
	return 0;
}

int recurs_power(int nn, int pp)
{
	if (pp == 0)
	{
		return 1;
	}
	return nn*recurs_power(nn,pp-1);
}
