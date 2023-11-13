/*
C11 ДЗ 
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе: 		Два целых положительных числа 
Данные на выходе: 	Одно целое число - наибольший общий делитель. 

Пример №1
Данные на входе: 		14 21 
Данные на выходе: 	7 
*/

#include <stdio.h>
#include <inttypes.h>



int chislo_1 = 0, chislo_2 = 0;

int nod(int a, int b);

int main(void)
{
	
	printf("Введите два целых положительных числа \n");
	scanf("%d %d \n",&chislo_1,&chislo_2);
	printf("НОД = %d \n", nod(chislo_1,chislo_2));	 	
	return 0;
}

int nod(int a, int b) 
{
    while (a != b)
    {
        (a > b) ? (a = a - b) : (b = b - a);
    }
	return a;
}
