/*
C13 Практика 
Вычислить cos
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... 
(x в радианах)
float cosinus(float x)

Данные на входе: 		Целое число от 0 до 90 
Данные на выходе: 	Вещественное число в формате "%.3f" 

Пример
Данные на входе: 		60 
Данные на выходе: 	0.500   
*/

#include <stdio.h>
#include <inttypes.h>

const float PI = 3.1415926535;

uint8_t x = 0; // значение угла в градусах

double cos(double alpha);
double factorial(int n); 			// функция вычисления факториала
double degree(double p, int m);		// функция вычисления степени

int main(void)
{
	printf("Введите целое число в градусах от 0 до 90 \n");
	scanf("%hhd \n",&x);
	printf("cos(x) = %.3f \n", cos(x));		 	
	return 0;
}

double cos(double alpha) 
{
	uint8_t i = 0;
	double rad = 0.0;
	double result = 0.0;
		
	rad = PI/180*alpha;

	for (i=1; i<=5; i++)
	{
		result += (degree((-1),(i-1))*degree(rad,(2*i - 2)))/factorial(2*i - 2); // общая формула для cos(x) через ряд Тейлора cos(x)=[(-1^(n-1))*(x^(2n-2))]/[(2n-2)!]
	}
	return result;
}
double factorial(int n) 
{
	uint16_t i = 0;
	double result = 1;
	
	for (i = 1; i <= n;i++)
	{
		result*=i;
	}
	return result;
}
double degree(double p, int m)
{
	uint16_t i = 0;
	double result = 1.0;
	
	for (i = 1; i <= m;i++)
	{
		result*=p;
	}
	return result;
}
