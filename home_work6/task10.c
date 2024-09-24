/* Простые множители
   Составить функцию, печать всех простых множителей числа.
   Использовать ее для печати всех простых множителей числа.
   void print_simple(int n)
   Формат входных данных:
   Целое положительное число.
   Формат результата:
   Последовательность всех простых множителей данного числа в порядке возрастания.
   Примеры:
   Входные данные:
   12
   Результат работы:
   2 2 3
   Входные данные:
   120
   Результат работы:
   2 2 2 3 5
*/

#include <stdio.h>
typedef unsigned int uint;
void p_factors(uint n);

int main(int argc, char** argv)
{
    uint data_a = 0;
    scanf("%d", &data_a);
    p_factors(data_a);
    return 0;
}

void p_factors(uint n)
{
    int d = 2;
    while (n != 1)
    {
        if (n % d == 0)
        {
            printf("%d ", d);
            n /= d;
        }
        else
            d += 1;
    }

}




