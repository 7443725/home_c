/* Возвести в степень
   Составить функцию, возведение числа N в степень P. 
   int power(n, p) и привести пример ее использования.
   Формат входных данных
   Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные:
   8 3
   Результат работы:
   512
   Входные данные:
  -5 2
   Результат работы:
   25
*/

#include <stdio.h>
int pow (int, int);

int main(int argc, char** argv)
{
    int data_a,degree;
    scanf("%d%d", &data_a, &degree);
    if(data_a <= 1000 && degree >=0)
         printf("%d", pow(data_a,degree));
    return 0;
}

int pow (int data, int deg)
{ 
    int a = 1;
    for (int i = 1; i <= deg; i++)
        a *= data;
    return a;
}