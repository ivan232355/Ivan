/*
 ============================================================================
Задача 5-2-Префикс и суфикс
На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки.
Каждая из строк не превышает по длине 104. В строках не встречаются пробельные символы.
На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса
первой строки, являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося
префиксом второй. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

Пример №1
Данные на входе:
don't_panic
nick_is_a_mastodon
Данные на выходе:	3 3
Пример №2
Данные на входе:
monty_python
python_has_list_comprehensions
Данные на выходе:	0 6
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prefix_to_suffix(char *S1,char *S2)
{
	int len_1= strlen(S1);
	int len_2= strlen(S2);
	int max_len = 0;

	for (int i=1; i<=len_1;i++)
	{
		if (i>len_2) break;
		if (strncmp(S1,S2+len_2-i,i)==0)
		{
			max_len=i;
		}

	}
	return max_len;
}

int suffix_to_prefix(char *S1,char *S2)
{
	int len_1= strlen(S1);
	int len_2= strlen(S2);
	int max_len = 0;

	for (int i=1; i<=len_1;i++)
	{
		if (i>len_2) break;
		if (strncmp(S2+len_2-i,S1,i)==0)
		{
			max_len=i;
		}

	}
	return max_len;
}


int main(void)
{

	char s1[104];
	char s2[104];

	scanf("%s", s1);
	scanf("%s", s2);

	int prefix_suffix = prefix_to_suffix(s1,s2);
	int suffix_prefix = suffix_to_prefix(s1,s2);

    // Выводим результат
    printf("%d %d\n", prefix_suffix,suffix_prefix);

    return 0;

}
