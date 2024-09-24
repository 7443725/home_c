/* Проверка на простоту
   Составить функцию логическую функцию, которая определяет, верно ли, что число простое. 
   Используя функцию решить задачу.
   int is_prime(int n)
   Формат входных данных:
   Одно целое не отрицательное число.
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   13
   Результат работы:
   YES
   Входные данные:
   136
   Результат работы:
   NO
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint is_prime(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    is_prime(data_a) ? printf("YES") : printf("NO");
    return 0;
}

uint is_prime(uint n)
{
    if(n == 0 || n == 1)
        return 0;
    for (int i = 2; i < n; i++) 
        if (n % i == 0)
           return 0;
    return 1;
}
