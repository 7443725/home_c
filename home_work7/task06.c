/* Строка наоборот
   Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот.
   Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
   void reverse_string()
   Формат входных данных
   Строка из английских букв и знаков препинания. В конце строки символ точка.
   Формат результата:
   Исходная строка задом наперед.
   Примеры:
   Входные данные:
   Hello world!.
   Результат работы:
   !dlrow olleH
*/

#include <stdio.h>
typedef unsigned int uint;
void reverse_string();

int main(int argc, char** argv)
{
    reverse_string();
    return 0;
}

void reverse_string()
{
    char data_a = 0;
    scanf("%c", &data_a);
    if (data_a != '.')
    {
        reverse_string();
        printf("%c", data_a);
    }
}