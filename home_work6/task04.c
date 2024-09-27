/* Функция по формуле
   Описать функцию вычисления f(x) по формуле:
   f(x)= x*x при -2 ≤ x < 2;
   x*x+4x+5 при x ≥ 2;
   4 при x < -2.
   Используя эту функцию для n заданных чисел, вычислить f(x).
   Среди вычисленных значений найти наибольшее.
   Формат входных данных:
   Последовательность не нулевых целых чисел, в конце последовательности число 0.
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные:
   8 3 -3 10 0
   Результат работы:
   145
   Входные данные
   -2 -1 -3 1 0
   Результат работы
   4
*/

#include <stdio.h>
typedef unsigned int uint;
int f(int x);

int main(int argc, char** argv)
{
    int data_a = 1, data_b = 0, max = 0;
    while (data_a != 0)
    {
        scanf("%d", &data_a);
        data_b = f(data_a);
        if (data_b > max)
            max = data_b;
    }
    printf("%d ", max);
    return 0;
}

int f(int x)
{
    int a = 0;
    if ((x >= -2) && (x < 2))
        a = x * x;
    else if (x >= 2)
        a = x * x + 4 * x + 5;
    else if (x < -2)
        a = 4;
    return a;
}
 

