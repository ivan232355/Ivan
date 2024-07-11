/*
 ============================================================================
 Name        : 10.c
 Author      : 
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 Необходимо реализовать только одну функцию (всю программу писать не надо!!!), которая упаковывает переданный ей массив из
 32-ух элементов 0 и 1 в указанную структуру данных.
 Функция должна строго соответствовать прототипу: void array2struct(int [], struct pack_array *)
 Загрузите только одну функцию или просто вставьте ее текст void array2struct(int [], struct pack_array *)
 Пример №1
 Данные на входе:		1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 Данные на выходе:
 Поля структуры
 array = ffff0000
 count0 = 16
 count1 = 16

 Пример №2
 Данные на входе:		1 1 1 1 1 1 1 1 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1
 Данные на выходе:
 Поля струткуры
 array = ffa70009
 count0 = 17
 count1 = 15

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pack_array
{
	uint32_t array; 		// поле для хранения упакованного массива из 0 и 1
	uint32_t count0 : 8; 	// счетчик нулей в array
	uint32_t count1 : 8; 	// счетчик единиц в array
};
void array2struct(int input[], struct pack_array *output)
{
    output->array = 0; // Инициализируем переменные
    output->count0 = 0;
    output->count1 = 0;

	for (int i = 0; i <32; i++)
	{
		if (input[i] == 1)
		{
			output->array |= (1<<(31-i)); // Если нашли 1 поочередно сдвигаем ее вправо заполняя массив
			output->count1++;
		}else
		{
			output->count0++;
		}
	}
}
int main(void)
{
	int input1[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	struct pack_array output1;

	array2struct(input1,&output1);

    printf("array = %08x\n", output1.array);
    printf("count0 = %u\n", output1.count0);
    printf("count1 = %u\n", output1.count1);

    int input2[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0,
    		0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1};

    struct pack_array output2;

    array2struct(input2,&output2);

    printf("array = %08x\n", output2.array); // Выводим 8 символов формата HEX
    printf("count0 = %u\n", output2.count0);
    printf("count1 = %u\n", output2.count1);


}
