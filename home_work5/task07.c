/* Ровно одна цифра 9
   Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
   Формат входных данных:
   Одно целое число
   Формат результата:
   Ответ: YES или NO
   Примеры:
   Входные данные:
   193
   Результат работы:
   YES
   Входные данные:
   1994
   Результат работы:
   NO
*/

#include <stdio.h>
#define ONE_FIGURE 9

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
    for (int a = i; a >= 0; a--)
        if (data_b[a] == ONE_FIGURE)
            data_a++;
    data_a ==1?printf("YES"):printf("NO");
    return 0;
}