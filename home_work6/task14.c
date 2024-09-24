/* Сумма цифр четна
   Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.
   Формат входных данных:
   Одно целое не отрицательное число
   Формат результата:
   Ответ YES или NO
   Примеры:
   Входные данные:
   136
   Результат работы:
   YES
   Входные данные:
   245
   Результат работы:
   NO
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint e_sum(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    e_sum(data_a) ? printf("YES") : printf("NO");
    return 0;
}

uint e_sum(uint n)
{
    int sum = 0;
    for (sum = 0; n > 0; n /= 10)
        sum += n % 10;
    return (sum % 2 == 0);
}
