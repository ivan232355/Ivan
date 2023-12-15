/*
G14
Hello name
В файле .txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие .txt, где останутся
имя и фамилия

Данные на входе: Строка состоящая из английских букв и пробелов не более 100 символов.
Формат: Фамилия Имя Отчество
Данные на выходе: 	Строка состоящая из английских букв и пробелов

Пример
Данные на входе: 		Pupkin Vasiliy Ivanovich
Данные на выходе: 	Hello, Vasiliy Pupkin!
 */

#include <stdio.h>
#include <string.h>

char input[] = "input.txt";
char output[] = "output.txt";
char name[100];
char first_Name[50], last_Name[50];

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    // Открытие файла для чтения
    if (input == NULL)
    {
        printf("Error occured while opening input file!\n");
        return 1;
    }

    // Открытие файла для записи
    if (output == NULL)
    {
        printf("Error occured while opening output file!\n");
        return 1;
    }

    // Считывание слова из файла
    fgets(name, 100, input);

    // Разделение строки на фамилию и имя
    sscanf(name, "%s %s", last_Name, first_Name);

    // Запись приветствия в файл
    fprintf(output, "Hello, %s %s!", first_Name, last_Name);

    // Закрытие файлов
    fclose(input);
    fclose(output);

    return 0;
}
