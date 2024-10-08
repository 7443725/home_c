/* В двоичную систему
   Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
   Формат входных данных
   Целое не отрицательное число в десятичной системе счисления
   Формат результата:
   Целое число в двоичной системе счисления
   Примеры:
   Входные данные:
   5
   Результат работы:
   101
   Входные данные:
   8
   Результат работы:
   1000
*/

#include <stdio.h>
typedef unsigned int uint;
void bin(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    bin(data_a);
    return 0;
}

void bin(uint n)
{
    if (n > 1)
        bin(n / 2);
    printf("%d", n % 2);
}
