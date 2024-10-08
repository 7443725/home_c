/* Среднее арифметическое чисел
   Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
   int middle(int a, int b)
   Формат входных данных:
   Два целых не отрицательных числа
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные:
   5 7
   Результат работы:
   6
   Входные данные:
   10 20
   Результат работы:
   15
*/

#include <stdio.h>
typedef unsigned int uint;
#define MID(a,b) (((a)+(b))/2)

int main(int argc, char** argv)
{
    uint data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    printf("%d", MID(data_a, data_b));
    return 0;
}
