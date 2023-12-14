/*
F8 Практ 2
Пропущенное число
Написать функцию и программу, демонстрирующую работу данной функции.
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1) в произвольном порядке,
но одно из чисел пропущено (остальные встречаются ровно по одному разу).
N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.

Данные на входе: 		Последовательность целых чисел от M до N. M, N не превосходит 1000.
Данные на выходе: 	Одно целое число

Пример №1
Данные на входе: 		2 3 1 4 7 6 9 8 10 0
Данные на выходе: 	5

Пример №2
Данные на входе: 		41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
Данные на выходе: 	35
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int s[10] = {2,3,1,4,7,6,9,8,10};
//int s[20] = {41,40,39,38,37,36,34,33,32,31,50,49,48,47,46,45,44,43,42,30};
//int s[10];
int size;
int number = 0;

//Функция нахождения максимума и минимума и вычисления суммы чисел найденного интервала
int find_sum_max_min(int arr[], int size, int *max, int *min)
{
    *max = arr[0];
    *min = arr[0];
    int sum;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        else if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
    sum = *min;
	for (int i = *min + 1; i <= *max; i++)
    {
        sum += i;
    }
	return sum;
}
// Функция нахождения недостающего числа
int find_number(int arr[], int size)
{
    int sum = 0;
    int start_arr = 0 , end_arr = 0;
    int sum_max_arr = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    sum_max_arr = find_sum_max_min(arr, size,&end_arr, &start_arr);
    return sum_max_arr - sum;
}

// Функция нахождения одинаковых чисел
int is_two_same(int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
// Проверка чисел больше 1000
int checking_number(int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
		if (a[i] > 1000)
		{
          printf("%d>1000!!!\n",a[i]);
          return 0;
		}
    }
    return 1;
}

int isDigit(char c)
{
    return ((c>='0')&&(c<='9'));
}

int InputGet(int arr[], int n)
{
int i;
char c;
    while((c=getchar())!='\n')
    {
        if(isDigit(c))
        {
            int number=0;
            do
            {
                number=number*10+c-'0';
                c=getchar();
            }
            while(isDigit(c));
            arr[i++] = number;
            if(c=='\n')
                break;
        }
    }
    return i;
}



int main()
{
    //size = InputGet(s, 100);
	size = sizeof(s)/sizeof(s[0]);

    if (!checking_number(size, s)) 		// проверяем, что все числа в массиве меньше или равны 1000
    {
        return 1;
    }

    if (is_two_same(size,s) == 1) 		// проверяем, есть ли одинаковые числа в массиве
    {
        printf("ERROR\n"); 				// если есть, выводим сообщение
    }
    else
    {
        number = find_number(s,size); 	// находим недостающее число
        printf("%d",number);
    }
    return 0;
}



