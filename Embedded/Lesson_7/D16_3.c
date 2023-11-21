/*
D16 Практик 3
Точная степень двойки
Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)
Данные на входе: 		Одно натуральное число. 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		8 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		7 
Данные на выходе: 	NO    
*/

#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

int a = 0,i = 0; 

int is2pow(int n);
		
int main(void)
{
	setlocale(LC_ALL, "");
	printf("Введите одно натуральное число\n");
    scanf("%d",&a);
	is2pow(a);
	return 0;
}

int is2pow(int n)
{
	if (n==1)
	{
		printf("NO");
		return 1;	
	}
	if (n%2 == 0 || n ==0)
	{
		printf("YES");
		return 0;
	}
	else
	{
		is2pow(n/2);	
	}
}
