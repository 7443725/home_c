/* Наибольший общий делитель
   Составить программу для вычисления НОД с помощью алгоритма Евклида. 
   Даны два натуральных числа. Найти наибольший общий делитель.
   Формат входных данных:
   Два неотрицательных целых числа
   Формат результата:
   Одно целое число наибольший общий делитель
   Примеры:
   Входные данные:
   14 21
   Результат работы:
   7
   Входные данные:
   27 18
   Результат работы:
   9
   */

#include <stdio.h>

int main(int argc, char** argv)
{
    unsigned int data_a,data_b;
    scanf("%d %d", &data_a,&data_b);
    while (data_a && data_b)
    {
         if(data_a > data_b)
               data_a %= data_b;
         else
               data_b %= data_a;
    }
    printf("%d", data_a + data_b);
    return 0;
}