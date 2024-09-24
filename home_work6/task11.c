/* НОД
   Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
   int nod(int a, int b)
   Формат входных данных:
   Два целых положительных числа
   Формат результата:
   Одно целое число - наибольший общий делитель.
   Примеры:
   Входные данные:
   14 21
   Результат работы:
   7
*/

#include <stdio.h>
typedef unsigned int uint;
uint nod(uint a, uint b);

int main(int argc, char** argv)
{
    uint data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    printf("%d", nod(data_a, data_b));
    return 0;
}

uint nod(uint a, uint b)
{
    while (a > 0 && b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

