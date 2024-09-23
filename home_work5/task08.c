/* Все цифры четные
   Ввести целое число и определить, верно ли, что все его цифры четные.
   Формат входных данных:
   Одно целое число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   2684
   Результат работы:
   YES
   Входные данные:
   2994
   Результат работы:
   NO
*/

#include <stdio.h>

int main(int argc, char** argv)
{
    int data_a, data_b[5], i = 0;
    scanf("%d", &data_a);
    while (data_a)
    {
        data_b[i] = data_a % 10;
        data_a /= 10;
        i++;
    }
    data_a = 0;
    for (int a = i - 1; a >= 0; a--)
        if (!(data_b[a] % 2))
            data_a++;
    data_a ==i?printf("YES"):printf("NO");
    return 0;
}