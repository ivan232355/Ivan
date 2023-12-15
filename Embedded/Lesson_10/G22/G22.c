/*
G22
Soundex
Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова
по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:
Первая буква слова сохраняется.
В остальной части слова:буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются;
оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют
одинаковые цифры:

1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r

Любая последовательность одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.

Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514

Данные на входе: Во входном файле .txt находится одно непустое слово, записанное строчными латинскими буквами.
Длина слова не превосходит 20 символов.
Данные на выходе: Напечатайте четырёхбуквенный код, соответствующий слову в файл .txt.


Пример №1
Данные на входе: 		ammonium
Данные на выходе: 	a500

Пример №2
Данные на входе: 		implementation
Данные на выходе: 	i514
*/
#include <stdio.h>
#include <string.h>

char input[] = "input.txt";
char output[] = "output.txt";
char str[21];
char soundex[5];
char result[5];

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
    fscanf(input, "%s", str);

    // Преобразование слова в Soundex
    soundex[0] = str[0]; // Первая буква сохраняется

    int j = 1;
    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'h' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'w' || str[i] == 'y')
        {
            continue; // Пропускаем гласные
        } else if (str[i] == 'b' || str[i] == 'f' || str[i] == 'p' || str[i] == 'v')
        {
            soundex[j++] = '1';
        } else if (str[i] == 'c' || str[i] == 'g' || str[i] == 'j' || str[i] == 'k' ||
                   str[i] == 'q' || str[i] == 's' || str[i] == 'x' || str[i] == 'z')
        {
            soundex[j++] = '2';
        } else if (str[i] == 'd' || str[i] == 't')
        {
            soundex[j++] = '3';
        } else if (str[i] == 'l')
        {
            soundex[j++] = '4';
        } else if (str[i] == 'm' || str[i] == 'n')
        {
            soundex[j++] = '5';
        } else if (str[i] == 'r')
        {
            soundex[j++] = '6';
        }
    }

    soundex[j] = '\0'; // Добавляем завершающий нуль-символ

    // Удаление последовательных одинаковых цифр
    result[0] = soundex[0];
    j = 1;
    for (int i = 1; i < strlen(soundex); i++)
    {
        if (soundex[i] != soundex[i - 1])
        {
            result[j++] = soundex[i];
        }
    }
    result[j] = '\0'; // Добавляем завершающий нуль-символ

    // Добавление нулей, если длина строки меньше 4
    while (strlen(result) < 4)
    {
        result[strlen(result)] = '0';
        result[strlen(result) + 1] = '\0';
    }

    // Запись результата в файл
    fprintf(output, "%s", result);

    // Закрытие файлов
    fclose(input);
    fclose(output);
    return 0;
}

