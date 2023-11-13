/*
C20 Задача со *
Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность. 

Данные на входе: 		На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов. 
Данные на выходе: 	Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае. 

Пример №1
Данные на входе: 		(()()). 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		()(. 
Данные на выходе: 	NO     
*/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>


char checkStr(char s[])
{
    int counter = 0;
    for (int i = 0; i < strlen(s); i++) // (+1, (+1 ,)-1, (+1, )-1, )-1 -> counter == 0 
    {
        if (s[i] == '(') 
        {
            counter++;
        } else if (s[i] == ')')
        {
            if (counter == 0)
            {
                return 0;
            } else
            {
                counter--;
            }
        }
    }
    if (counter == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
    
}

int main()
{
    char input_str[1000];
    printf("Введите строку состоящую из символов '(', ')' и заканчивающуюся символом '.'. Размер строки не более 1000 символов.\n");
    scanf("%s", input_str);
    
    char result = checkStr(input_str);
    if (result == 1)
    {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}


