/* Печать простых множителей
   Составить рекурсивную функцию, печать всех простых множителей числа.
   Формат входных данных:
   Натуральное число
   Формат результата:
   Последовательность из всех простых делителей числа через пробел
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
void rec(int a, int b);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    rec(data_a, 2);
    return 0;
}

void rec(int a, int b)
{
    if (a == 1)
        return;
    while(1)
    {
        if (a % b == 0)
        {
            printf("%d ", b);
            rec(a / b, b);
            return;
        }
        b++;
    }
}