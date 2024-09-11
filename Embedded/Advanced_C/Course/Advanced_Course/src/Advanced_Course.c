/*
 ============================================================================
Составьте программу, которая находит площадь, образуемую данными
уравнениями:

1. f1 = 0.6x + 3
2. f2 = (x − 2)^3 – 1
3. f3 = 3 / x
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// Определение функций
double f1(double x)
{
    return 0.6 * x + 3;
}

double df1(double x)
{
    return 0.6;
}

double f2(double x)
{
    return pow(x - 2, 3) - 1;
}

double df2(double x)
{
    return 3 * pow(x - 2, 2);
}

double f3(double x)
{
    return 3 / x;
}

double df3(double x)
{
    return -3/(x * x);
}

// Функция для нахождения корня уравнения методом Ньютона
/*▎Параметры функции

- double (*f)(double): Указатель на функцию f(x).
- double (*g)(double): Указатель на функцию g(x).
- double (*df)(double): Указатель на производную функции df(x).
- double (*dg)(double): Указатель на производную функции dg(x).
- double a, double b: Начальные границы интервала, в котором ищется корень.
- double eps: Допустимая погрешность (точность), с которой необходимо найти корень.
- int *iterations: Указатель на переменную, в которую будет записано количество итераций, потребовавшихся для нахождения корня.
*/
double root(double (*f)(double), double (*g)(double), double (*df)(double), double (*dg)(double),
		double a, double b, double eps, int *iterations)
{
    double x = (a + b) / 2;
    *iterations = 0;
    while (fabs(f(x) - g(x)) > eps)
    {
        x = x - (f(x) - g(x)) / (df(x) - dg(x));
        (*iterations)++;
        if (*iterations > 1000) // Ограничение на количество итераций
        {
            fprintf(stderr, "Couldn't find the root\n");
            exit(1);
        }
    }
    return x;
}

typedef double (*function)(double);

double calc_Integral_Trap(double xl, double xr, double n, function f)
{
	double sum = 0;
	double h = (xr - xl) / n;

    // Суммируем значения функции в узловых точках
    for (size_t i = 0; i < n; ++i)
    {
    	double x_left = xl + i * h;
    	double x_right = x_left + h;
        sum += 0.5 * h * (f(x_left) + f(x_right));
    }

    return sum;
}
// Вывод справки по ключу --help
void print_help()
{
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  --help          Show this help message\n");
    printf("  --crossing      Print the x-coordinates of intersection points\n");
    printf("  --iterations    Print the number of iterations for finding roots\n");
}



int main(int argc, char *argv[])
{
	// Обработка командной строки
	    int print_crossing = 0;
	    int print_iterations = 0;

	    for (int i = 1; i < argc; i++)
	    {
	        if (strcmp(argv[i], "--help") == 0)
	        {
	            print_help();
	            return 0;
	        } else if (strcmp(argv[i], "--crossing") == 0)
	        {
	            print_crossing = 1;
	        } else if (strcmp(argv[i], "--iterations") == 0)
	        {
	            print_iterations = 1;
	        }
	    }

	    int crossing1, crossing2, crossing3;
	    double eps1 = 1e-5; // Точность для нахождения корней
	    double eps2 = 10000.0; // Точность для интегрирования

	    // Нахождение точек пересечения
	    double x1 = root(f1, f2, df1, df2, 0.0, 5.0, eps1, &crossing1);
	    double x2 = root(f2, f3, df2, df3, 0.5, 5.0, eps1, &crossing2);
	    double x3 = root(f1, f3, df1, df3, 0.0, 2.0, eps1, &crossing3);

	    // Вычисление интегралов
	    double integral1 = calc_Integral_Trap(x3,x1,eps2,f1);
	    double integral2 = calc_Integral_Trap(x2,x1,eps2,f2);
	    double integral3 = calc_Integral_Trap(x3,x1,eps2,f3);

	    // Вывод результатов
	    if (print_crossing)
	    {
	        printf("Cross point: x1 = %lf, x2 = %lf, x3 = %lf\n", x1, x2, x3);
	    }

	    if (print_iterations) {
	        printf("Number of iterations: iterations1 = %d, iterations2 = %d, iterations3 = %d\n", crossing1, crossing2, crossing3);
	    }

	    printf("Integral:\n");
	    printf("Integral from x1 to x2 (f1): %lf\n", integral1);
	    printf("Integral from x2 to x3 (f2): %lf\n", integral2);
	    printf("Integral from x1 to x3 (f3): %lf\n", integral3);
	    double sumIntegral = integral1 - integral2 - integral3;  // Площадь пересечений 3х функций
	    printf("Total area f1 f2 f3: %lf\n", sumIntegral);
	    return 0;
}
