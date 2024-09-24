/* Сумма цифр равна произведению
   Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.
   int is_happy_number(int n)
   Формат входных данных:
   Целое не отрицательное число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   123
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
uint is_happy_number(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    is_happy_number(data_a) ? printf("YES") : printf("NO");
    return 0;
}

uint is_happy_number(uint n)
{
    if(n == 0)
        return 1;
    uint summ = 0, product = 1;
    while (n > 0)
    {
        summ += n % 10;
        product *= n % 10;
        n /= 10;
    }
    if (summ == product)
        return 1;
    return 0;
}
