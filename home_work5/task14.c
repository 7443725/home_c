/* Количество четных чисел
   Дана последовательность ненулевых целых чисел, в конце последовательности число 0. 
   Посчитать количество четных чисел.
   Формат входных данных:
   Последовательность ненулевых целых чисел. В конце последовательности число ноль.
   Формат результата:
   Одно целое число - количество четных чисел.
   Примеры:
   Входные данные:
   15 22 2 4 1 6 0
   Результат работы:
   4
   Входные данные:
   27 1 3 7 0
   Результат работы:
   0
   */

#include <stdio.h>

int main(int argc, char** argv)
{
    int data_a,count = 0;
    do
    {
         scanf("%d", &data_a);
         if(!(data_a % 2) && data_a)
              count++;   
    }while (data_a);
    printf("%d", count);
    return 0;
}