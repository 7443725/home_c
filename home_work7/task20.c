/* Возвести в степень
   Написать рекурсивную функцию возведения целого числа n в степень p.
   int recurs_power(int n, int p)
   Используя данную функцию, решить задачу.
   Формат входных данных:
   Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100
   Формат результата:
   Одно целое число n в степени p
   Примеры:
   Входные данные:
   2 3
   Результат работы:
   8
   Входные данные:
   3 4
   Результат работы:
   81
*/

#include <stdio.h>
typedef unsigned int uint;
int recurs_power(int n, int p);

int main(int argc, char** argv)
{
    int data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    printf("%d ", recurs_power(data_a, data_b));
    return 0;
}

int recurs_power(int n, int p)
{
    static int a = 1;
    if (p)
    {
        a *= n;
        recurs_power(n, p - 1);
    }
    return a;
}