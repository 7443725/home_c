/* Количество 1
   Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. Составить рекурсивную функцию.
   Формат входных данных
   Натуральное число
   Формат результата
   Целое число - количество единиц в двоичной записи числа.
   Примеры:
   Входные данные:
   5
   Результат работы:
   2
   Входные данные:
   255
   Результат работы:
   8
*/

#include <stdio.h>
typedef unsigned int uint;
uint bin(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    printf("%d ", bin(data_a));
    return 0;
}

uint bin(uint n)
{ 
    static uint a = 0;
    if (n > 1)
        bin(n / 2);
    return a += n % 2;
}
