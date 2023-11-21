/*
D18 Практик 2
Цифры слева направо
Написать рекурсивную функцию и используя ее решить задачу. Напечатать цифры введенного натурального числа в порядке следования(слева направо) через пробел.
void print_digits(int n)
Данные на входе: 		Натуральное число
Последовательность цифр в слева направо через пробел

Пример №1
Данные на входе: 		12345
Данные на выходе: 	1 2 3 4 5

Пример №2
Данные на входе: 		709
Данные на выходе: 	7 0 9
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a = 0;

void print_digits(int n);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("Введите натуральное число\n");
	scanf("%d",&a);
	print_digits(a);
	return 0;
}

void print_digits(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
    } else
    {
        print_digits(n / 10);
        printf("%d ", n % 10);
    }
}
