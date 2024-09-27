/* Сумма чисел от 1 до N
   Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
   Формат входных данных:
   Одно натуральное число
   Формат результата:
   Сумма чисел от 1 до введенного числа
   Примеры:
   Входные данные:
   5
   Результат работы:
   15
   Входные данные:
   100
   Результат работы:
   5050
*/

#include <stdio.h>
typedef unsigned int uint;
uint one_to_n(uint);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    printf("%d ", one_to_n(data_a));
    return 0;
}

uint one_to_n(uint a)
{
    static int summ = 0;
    summ += a;
    if (a > 1)
        one_to_n(a - 1);
    return summ;
}