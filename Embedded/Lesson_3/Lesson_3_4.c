
#include <stdio.h>


double a = 0,b = 0,c = 0;
double midlle = 0;

int main(void)
{
	printf("Введите три целых целых числа через пробел и q для завершения\n");
	scanf("%lf %lf %lf\n",&a,&b,&c);
	midlle = (a + b + c)/3;
	printf("%.2lf\n",midlle);
	return 0;
}

