/*
D8 ДЗ 2
От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.

Данные на входе: 		Два целых числа через пробел. 
Данные на выходе: 	Последовательность целых чисел. 

Пример №1
Данные на входе: 		5 2 
Данные на выходе: 	5 4 3 2 

Пример №2
Данные на входе: 		2 7 
Данные на выходе: 	2 3 4 5 6 7     
*/

#include <stdio.h>
#include <inttypes.h>

int a = 0,b = 0; 
uint8_t dir = 0;
void print_num(int aa, int bb, uint8_t direction);
		
int main(void)
{
	printf("Введите два целых числа через пробел\n");
	scanf("%d %d",&a,&b);
	(a<b) ? (dir = 1) : (dir = 0);
	print_num(a,b,dir);
	
	return 0;
}

void print_num(int aa, int bb, uint8_t direction) 
{
	if (direction == 1)
	{
		if (aa <= bb)
		{
			printf("%d ",aa);
			print_num(aa+1,bb,dir);
		}
		else
		{
			return;
		}
	}
	else 
	{
		if (aa >= bb)
		{
			printf("%d ",aa);
			print_num(aa-1,bb,dir);
		}
		else
		{
			return;
		}
	}
}
