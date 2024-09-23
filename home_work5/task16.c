/* Все счастливые числа
   Ввести натурально число и напечатать все числа от 10 до введенного числа -
   у которых сумма цифр равна произведению цифр
   Формат входных данных:
   Одно натуральное число большее 10
   Формат результата:
   Числа у которых сумма цифр равна произведению цифр через пробел в порядке возрастания.
   Не превосходящие введенное число.
   Примеры:
   Входные данные:
   200
   Результат работы:
   22 123 132
   Входные данные:
   1000
   Результат работы:
   22 123 132 213 231 312 321
   Входные данные:
   22
   Результат работы:
   22
   */

#include <stdio.h>
typedef unsigned int uint;

int main(int argc, char** argv)
{
    uint data_a, data_b[8];
    scanf("%d", &data_a);
    for (uint data_c = 10,i = 0, data_z; data_c <= data_a; data_c++,i = 0)
    {
        data_z = data_c;
        for (; data_z;i++)
        {
            data_b[i] = data_z%10;
            data_z /= 10;
        }
        data_b[i] = '0';
        uint data_f = 0, data_d = 1;
        for (i = 0; data_b[i] != '0'; i++)
        {
            data_f += data_b[i];
            data_d *= data_b[i];
        }
        if (data_f == data_d)
            printf("%d ", data_c);
    }
    return 0;
}