/* Сумма цифр в тексте
   Составить функцию, которая преобразует текущий символ цифры в число. 
   Написать программу считающую сумму цифр в тексте.
   int digit_to_num(char c)
   Формат входных данных:
   Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка.
   Формат результата:
   Целое число - сумма цифр в тексте
   Примеры:
   Входные данные:
   1Hello 36world.
   Результат работы:
   10
   Входные данные:
   abc 1def2 3.
   Результат работы:
   6
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint digit_to_num(char c);

int main(int argc, char** argv)
{
    char c = '0';
    uint data_a = 0;
    while(c != '.')
    {
        scanf("%c", &c);
        data_a += digit_to_num(c);
    }
    printf("%d",data_a);
    return 0;
}

uint digit_to_num(char c)
{
    uint data_b = 0;
    if(c >= '0' && c <= '9')
        data_b = c - '0';    
    return data_b;
}
