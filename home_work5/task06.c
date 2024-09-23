/* Две одинаковые цифры
   Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, 
   НЕ обязательно стоящие рядом.
   Формат входных данных:
   Одно целое число
   Формат результата:
   Одно слово: YES или NO
   Примеры:
   Входные данные:
   1234
   Результат работы:
   NO
   Входные данные:
   1242
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
    for (int a = i; a >= 0; a--)
        for(int b = a - 1; b >= 0; b--)
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