/*
G4 ДЗ 1
По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл .txt в лексикографическом порядке.

Данные на входе: 		Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: 	Маленькие английские буквы через пробел.

Пример №1
Данные на входе: 		hello world
Данные на выходе: 	o


Данные на входе: 		aabcd bcef
Данные на выходе: 	b c

*/

#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char word_1[100] = {0,}, word_2[100] = {0,};
    unsigned char count_1[256] = {0,};
    unsigned char count_2[256] = {0,};
    int i = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    fscanf(input, "%s %s", word_1, word_2);

    // Подсчет количества каждого символа в каждом слове по таблице ASCII
    for (i = 0; i < strlen(word_1); i++)
    {
        count_1[word_1[i]]++;
    }
    for (i = 0; i < strlen(word_2); i++)
    {
        count_2[word_2[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if (count_1[i] == 1 && count_2[i] == 1)
        {
            fprintf(output, "%c ", (char)i);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
