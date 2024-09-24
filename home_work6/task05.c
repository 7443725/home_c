/* Сумма от 1 до N
   Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
   Формат входных данных
   Одно целое положительное число N
   Формат результата:
   Целое число - сумма чисел от 1 до N
   Примеры:
   Входные данные:
   100
   Результат работы:
   5050
*/

#include <stdio.h>
typedef unsigned int uint;
uint SUMM(uint x);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    printf("%d ", SUMM(data_a));
    return 0;
}

uint SUMM(uint x)
{   
    uint summ = 0;
    for (uint i = 1; i <= x; i++)
        summ += i;
    return summ ;
}



 


