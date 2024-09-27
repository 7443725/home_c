/* Посчитать числа
   Дана последовательность ненулевых целых чисел, в конце последовательности число 0. 
   Посчитать количество чисел.
   Формат входных данных:
   Целые ненулевые числа. В конце последовательности ноль. Ноль в последовательность не входит.
   Формат результата:
   Одно целое число - количество чисел в последовательности.
   Примеры:
   Входные данные:
   15 22 2 4 1 6 0
   Результат работы:
   6
   Входные данные:
   27 1 3 7 0
   Результат работы:
   4
   */

#include <stdio.h>

int main(int argc, char** argv)
{
    int data_a,count = 0;
    do
    {
         scanf("%d", &data_a);
         if(data_a)
              count++;   
    }while (data_a);
    printf("%d", count);
    return 0;
}