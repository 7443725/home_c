/* Перевести число N в систему счисления P
   Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
   Формат входных данных:
   Два целых числа. N ≥ 0 и 2 ≥ P ≥ 9
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные
   25 5
   Результат работы:
   100
   Входные данные:
   9 2
   Результат работы:
   1001
   Входные данные:
   11 3
   Результат работы:
   102
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint f(uint, uint);

int main(int argc, char** argv)
{
    uint data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    if(data_a >= 0 && data_b >=2 && data_b <= 9 )
        printf("%d ", f(data_a, data_b));
    return 0;
}

uint f(uint a, uint b)
{
    uint sum, exp = 1, r = 0;
    for (; a > 0; a /= b)
    {
        sum = a % b;
        r += sum * exp;
        exp *= 10;
    }
    return r;
}