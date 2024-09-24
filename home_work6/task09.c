/* Факториал
   Составить функцию вычисления N!.
   Использовать ее при вычислении факториала
   int factorial(int n)
   Формат входных данных:
   Целое положительное число не больше 20
   Формат результата:
   Целое положительное число
   Примеры:
   Входные данные:
   5
   Результат работы:
   120
*/

#include <stdio.h>
typedef unsigned int uint;
uint factorial(uint n);

int main(int argc, char** argv)
{
    uint data_a = 0;
    scanf("%d", &data_a);
    if (data_a >= 0 && data_a <= 20)
        printf("%d", factorial(data_a));
    return 0;
}

uint factorial(uint n)
{
    uint res = 1;
    for (uint i = 1; i <= n; i++)
        res *= i;
    return res;
}