/*
G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов.
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные.
Результат записать в .txt.

Данные на входе: 		Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Пример
Данные на входе: 		aabbccddABCD
Данные на выходе: 	bbaaccddBACD

*/

#include <stdio.h>
#include <string.h>

int main()
{
	char word_A[1000] = {0,};
	char word_B[1000] = {0,};

    int i = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    fscanf(input, "%s", word_A);

    for (i = 0; i<strlen(word_A);i++)
    {
        if (word_A[i] == 'a')
        {
        	word_B[i] = 'b';
        }
        else if (word_A[i] == 'b')
        {
        	 word_B[i] = 'a';
        }
        else if (word_A[i] == 'A')
        {
        	 word_B[i] = 'B';
        }
        else if (word_A[i] == 'B')
        {
        	 word_B[i] = 'A';
        }
        else word_B[i] = word_A[i];

    }
    fprintf(output, "%s ", word_B);

    fclose(input);
    fclose(output);
    return 0;
}

