/*
 ============================================================================
Задача 5-3-Польская запись
Необходимо вычислить выражение написанное в обратной польской записи. На вход подается строка состоящая из целых, не отрицательных чисел и арифметических символов. В ответ единственное целое число - результат. Более подробно об Обратной польская запись числа можно также почитать тут
Формат ввода:
Строка состоящая из целых чисел и символов '+', '-', '*', '/', ' '. В конце строки символ '.'. Строка корректная. Длина строки не превосходит 1000 символов. Все числа и операции разделены ровно одним пробелом.
Формат вывода:
Целое число, результат вычисления выражения.
Пример №1
Данные на входе:		3 4 +
Данные на выходе:	7
Пример №2
Данные на входе:		1 2 + 4 × 3 +
Данные на выходе:	15
Пример №3
Данные на входе:		100 25 + 25 /
Данные на выходе:	5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define false 0
#define true 1

#define MAX_STACK_SIZE 1000

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}Stack;

// функция записи в стэк
void push(Stack *stack, int value)
{
	if (stack->top < MAX_STACK_SIZE - 1)
	{
		stack->data[++(stack->top)]=value;
	}else
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
}

// функция удаления из стэка
int pop(Stack *stack)
{
	if (stack->top>=0)
	{
		return stack->data[(stack->top)--];
	}else
	{
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
}

int RPE(char *expression)
{
	Stack stack;
	stack.top = -1; // стэк пуст
	char *token = strtok(expression," "); // Строка разбивается на токены  разделенные пробелом

	while(token != NULL)
	{
		if (isdigit(token[0])) // если
		{
			push(&stack,atoi(token));
		}else
		{
			int a = pop(&stack);
			int b = pop(&stack);

			switch (token[0])
			{
				case '+': push(&stack, a+b); break;
				case '-': push(&stack, a-b); break;
				case '*': push(&stack, a*b); break;
				case '/': push(&stack, a/b); break;
				default :
					printf("Invalid operator: %s\n", token);
					exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL," ");
	}
	return pop(&stack);
}
int main(void)
{
	char expression[MAX_STACK_SIZE] = {0,};


	fgets(expression,sizeof(expression),stdin); // Ввод строки
	int result = RPE(expression);
	printf("%d",result);

	return 0;
}
