/* Две одинаковые цифры рядом
   Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
   Формат входных данных:
   Одно целое число
   Формат результата:
   Единственное слов: YES или NO
   Примеры:
   Входные данные:
   1232
   Результат работы:
   NO
   Входные данные:
   1224
   Результат работы:
   YES
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
    for (int a = i, b = i - 1; b >= 0; a--, b--)
    {
        if (data_b[a] == data_b[b])
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}