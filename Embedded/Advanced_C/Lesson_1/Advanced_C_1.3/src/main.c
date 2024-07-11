/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
 Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число.
Пример №1
Данные на входе:		2 1
Данные на выходе:	1
Пример №2
Данные на входе:		1 2
Данные на выходе:	1073741824
Пример №3
Данные на входе:		3 1
Данные на выходе:	2147483649
Пример №4
Данные на входе:		12 2
Данные на выходе:	3
Пример №5
Данные на входе:		19 3
Данные на выходе:	1610612738
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct
{
    uint32_t N;
    unsigned int K;

} BitShift;


int main(void)
{
    BitShift bs;

    // Считываем значения N и K
    if (scanf("%u %d", &bs.N, &bs.K) != 2)
    {
        printf("Ошибка ввода\n");
        return 1;
    }
    uint32_t result = (bs.N >> bs.K) | (bs.N << (32 - bs.K));
    printf("%u\n", result);
    return 0;
}
