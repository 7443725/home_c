/* Наименьшая и наибольшая цифра
   Организовать ввод натурального числа с клавиатуры.
   Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.
   Формат входных данных:
   Целое неотрицательное число
   Формат результата:
   Две цифры через пробел. Сначала наименьшая цифра числа, затем наибольшая.
   Примеры:
   Входные данные:
   15
   Результат работы:
   1 5
   Входные данные:
   2457
   Результат работы:
   2 7
   Входные данные:
   22
   Результат работы:
   2 2
   */

#include <stdio.h>

int main(int argc, char** argv)
{
    unsigned int data_a,min = 10, max = 0;
    scanf("%d", &data_a);
    while (data_a) 
    {
        int temp = data_a % 10;
        if (temp > max)
            max = temp;
        if (temp < min)
            min = temp;
        data_a = data_a / 10;
    }
    printf("%d %d", min, max);
    return 0;
}