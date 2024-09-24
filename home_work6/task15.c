/* Цифры по возрастанию
   Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию.
   Используя данную функцию решить задачу.
   int grow_up(int n)
   Формат входных данных:
   Одно целое не отрицательное число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   258
   Результат работы:
   YES
   Входные данные:
   528
   Результат работы:
   NO
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint grow_up(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    grow_up(data_a) ? printf("YES") : printf("NO");
    return 0;
}

uint grow_up(uint n)
{
    uint sum[8], i, d;
    if (!n)
        return 1;
    for (i = 0; n > 0; n /= 10, i++)
        sum[i] = n % 10;
    d = --i;
    while (i > 0)
    {
        uint b = sum[i--];
        if (b < sum[i])
            d--;
    }
    if (!d)
        return 1;
    return 0;
}
