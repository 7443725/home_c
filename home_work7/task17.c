/* Функция Аккермана
   Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:

   Реализуйте данную функцию по прототипу
   int akkerman(int m, int n)
   Формат входных данных:
   Даны неотрицательные целые числа m и n
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные:
   2 1
   Результат работы:
   5
   Входные данные:
   2 4
   Результат работы:
   11
*/

#include <stdio.h>
typedef unsigned int uint;
int akkerman(uint m, uint n);

int main(int argc, char** argv)
{
    uint data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    printf("%d ", akkerman(data_a, data_b));
    return 0;
}

int akkerman(uint m, uint n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        akkerman(m - 1, 1);
    else if (m > 0 && n > 0)
        akkerman(m - 1, akkerman(m, n - 1));
}