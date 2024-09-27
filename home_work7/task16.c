/* Точная степень двойки
   Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
   int is2pow(int n)
   Формат входных данных:
   Одно натуральное число.
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   8
   Результат работы:
   YES
   Входные данные:
   7
   Результат работы:
   NO
*/

#include <stdio.h>
#define true 1
#define false 0
typedef unsigned int uint;
int is2pow(double n);

int main(int argc, char** argv)
{
    int data_a;
    scanf("%d", &data_a);
    is2pow(data_a) ? printf("YES") : printf("NO");
    return 0;
}

int is2pow(double n)
{
    if (n == 1)
        return true;
    else if (n == 0)
        return false;
    else if (n > 1 && n < 2)
        return false;
    else
        is2pow(n / 2);
}