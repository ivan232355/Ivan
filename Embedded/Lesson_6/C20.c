/*
C20 ����� � *
������
�஢���� ��ப� ������� �� ᪮��� "(" � ")" �� ���४⭮���. 

����� �� �室�: 		�� �室 �������� ��ப� ������ �� ᨬ����� '(', ')' � �����稢������ ᨬ����� '.'. ������ ��ப� �� ����� 1000 ᨬ�����. 
����� �� ��室�: 	����室��� �������� ᫮�� YES �᫨ ᪮��� ���⠢���� ��୮ � NO � ��⨢��� ��砥. 

�ਬ�� �1
����� �� �室�: 		(()()). 
����� �� ��室�: 	YES 

�ਬ�� �2
����� �� �室�: 		()(. 
����� �� ��室�: 	NO     
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
    printf("������ ��ப� ������� �� ᨬ����� '(', ')' � �����稢������� ᨬ����� '.'. ������ ��ப� �� ����� 1000 ᨬ�����.\n");
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


