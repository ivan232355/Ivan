/*
C15 Практ 
Цифры по возрастанию

Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.

int grow_up(int n)

Данные на входе: 		Одно целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		258 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		528 
Данные на выходе: 	NO    
*/

#include <stdio.h>
#include <inttypes.h>


int x = 0;

int grow_up(int n);

int main(void)
{
	printf("Введите целое число \n");
	scanf("%d \n",&x);
	int result = grow_up(x);
	(result == 1) ? printf("YES\n") : printf("NO\n");		 	
	return 0;
}

int grow_up(int n) 
{
    int flag = 1;
    while (n!=0)
    {
		
		if (n%10<=(n/10)%10)
		{
			flag = 0;
		}		
		n=n/10;
	}
    return flag;
}

