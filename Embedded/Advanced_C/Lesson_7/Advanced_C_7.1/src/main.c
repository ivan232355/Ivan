/*
	Задача 7-1-Отсортировать слова
	Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом.
	Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы.
	Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
	struct list {
	   char word[20];
	   struct list *next;
	 }


	Необходимо реализовать односвязный список и обслуживающие его функции. add_to_list swap_elements print_list delete_list
	Формат ввода:
	Строка из английских символов 'a'-'z' и пробелов. В конце строки символ '.'. Длинна строки не более 1000 символов.
	Формат вывода:
	Упорядоченные по алфавиту слова.

	Пример №1
	Данные на входе:		efg abcd zzz.
	Данные на выходе:	abcd efg zzz
	Пример №2
	Данные на входе:		fffff kkkkkk a.
	Данные на выходе:	a fffff kkkkkk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 20

typedef struct list
{
	char word[WORD_SIZE];
	struct list *next;  	// Указывает на сдедующую структуру в списке
}list;

// Функция для добавления элемента в список
list* add_to_list( list *head, const char* word)
{
	list* new_node =(list*)malloc(sizeof(list));
	if (!new_node)
	{
        printf("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
	}
	strcpy(new_node->word,word);
	new_node->next = head;
	return new_node;
}

// Функция для вывода списка
void print_list(list *head)
{
    list *current = head;
    while (current != NULL)
    {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void swap_elements(list *a, list *b)
{
	char temp[20]; 				// Временный массив
	strcpy(temp,a->word); 		// Копируем строку из первого узла во временный массив
	strcpy(a->word,b->word); 	// Копирование строки из второго узла в первый
	strcpy(b->word, temp);		// Копирование строки из временного массива во второй узел

}

void sort_list(list *head)
{
	int flag_swap = 0;
	list *ptr1;
	list *lptr;

	if (head == NULL)
	{
		return;  // Сортировать нечего
	}
	do
	{
		flag_swap = 0;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (strcmp(ptr1->word,ptr1->next->word) > 0)
			{
				swap_elements(ptr1,ptr1->next);
				flag_swap = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}while(flag_swap);
}
int main(void)
{
	char input[1000];

	printf("Введите строку: \n");
	fgets(input,sizeof(input),stdin);

	// Удаляем символ точки в конце строки
	input[strlen(input) - 2] = '\0';

	//Разбиваем строку на слова идущие через пробел
	char *token = strtok(input," ");
	list* head = NULL;

    while (token != NULL)
    {
        head = add_to_list(head, token);
        token = strtok(NULL, " ");
    }
    // Сортируем список
    sort_list(head);

    // Выводим отсортированные слова
    print_list(head);

    printf("Нажмите Enter для выхода...");
    getchar(); // Ожидание ввода
    return 0;
}
