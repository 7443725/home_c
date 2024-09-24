/* Количество цифр в тексте
   Составить логическую функцию, которая определяет, что текущий символ это цифра. 
   Написать программу считающую количество цифр в тексте.
   int is_digit(char c)
   Формат входных данных:
   Текст из английских букв и знаков препинания. В конце текста символ точка.
   Формат результата:
   Одно целое число - количество цифр в тексте.
   Примеры:
   Входные данные:
   1Hello 36world.
   Результат работы:
   3
   Входные данные:
   abcd.
   Результат работы:
   0
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint is_digit(char c);

int main(int argc, char** argv)
{
    char c = '0';
    uint data_a = 0;
    while(c != '.')
    {
        scanf("%c", &c);
        data_a = is_digit(c);
    }
    printf("%d",data_a);
    return 0;
}

uint is_digit(char c)
{
    static uint data_b = 0;
    if(c >= '0' && c <= '9')
        data_b++;    
    return data_b;
}
