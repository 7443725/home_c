/* Сумма цифр равна 10
   Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
   Формат входных данных:
   Натуральное число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   1234
   Результат работы:
   YES
   Входные данные:
   1233
   Результат работы:
   NO
   */

#include <stdio.h>
typedef unsigned int uint;

int main(int argc, char** argv)
{
    uint data_a, data_b[8], i = 0, data_c = 0;
    scanf("%d", &data_a);
    for (; data_a; i++)
    {
        data_b[i] = data_a % 10;
        data_a /= 10;
    }
    data_b[i] = '0';
    i = 0;
    for (; data_b[i] != '0'; i++)
        data_c += data_b[i];
    if (data_c == 10)
        printf("YES");
    else
        printf("NO");
    return 0;
}

