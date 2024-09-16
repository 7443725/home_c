/* Сумма максимума и минимума
   Напечатать сумму максимума и минимума.
   Формат входных данных:
   Пять целых чисел через пробел
   Формат результата:
   Одно целое число - сумма максимума и минимума
   Примеры:
   Входные данные:
   4    15    9    56    4
   Результат работы:
   60 
*/


#include <stdio.h>

int main (int argc, char **argv) 
{
    int buf[5],min = 65535,max = 0;
    for(int i = 0; i < 5 ;i++)
        scanf(" %d", buf+i);
    for(int i = 0; i < 5; i++)
    {
        if(buf[i] < min)
            min = buf[i];
        if(buf[i] > max)
            max = buf[i];
    }   
    printf("%d\n",min + max);
    return 0; 
}