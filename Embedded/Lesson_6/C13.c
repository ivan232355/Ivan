/*
C13 �������� 
��������� cos
��������� �������, ������� ��������� ����� ��� ����� ���� (� ��������� 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... 
(x � ��������)
float cosinus(float x)

������ �� �����: 		����� ����� �� 0 �� 90 
������ �� ������: 	������������ ����� � ������� "%.3f" 

������
������ �� �����: 		60 
������ �� ������: 	0.500    
*/

#include <stdio.h>
#include <inttypes.h>

const float PI = 3.1415926535;

uint8_t x = 0; 

double cos(double alpha);
double factorial(int n); 			
double degree(double p, int m);		

int main(void)
{
	printf("������� ����� �������� � �������� �� 0 �� 90 \n");
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
		result += (degree((-1),(i-1))*degree(rad,(2*i - 2)))/factorial(2*i - 2); // cos(x)=[(-1^(n-1))*(x^(2n-2))]/[(2n-2)!]
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
