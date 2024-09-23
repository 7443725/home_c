/* Все цифры в порядке возрастания
   Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.
   Формат входных данных:
   Целое число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   1238
   Результат работы:
   YES
   Входные данные:
   1274
   Результат работы:
   NO
*/

#include <stdio.h>

int main(int argc, char** argv)
{
    int data_a, data_b[5], i = 0, c = 0;
    scanf("%d", &data_a);
    while (data_a)
    {
        data_b[i] = data_a % 10;
        data_a /= 10;
        i++;
    }
    data_a = 0;
    for (int a = i - 1, b = i - 2; b >= 0; a--, b--, c++)
        if (data_b[a] < data_b[b])
            data_a++;
    data_a == c ? printf("YES") : printf("NO");
    return 0;
}