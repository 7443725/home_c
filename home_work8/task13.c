/* Вторая с конца ноль
   Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.
   Формат входных данных
   10 целых чисел через пробел.
   Формат результата
   Целые числа через пробел, у котороых вторая с конца цифра - ноль
   Примеры
   Входные данные
   40 105 203 1 14 1000 22 33 44 55
   Результат работы
   105 203 1 1000
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
uint mass_b(int* arr, int* arr_b, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 }, data_b[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    output(data_b, mass_b(data_a, data_b, size_ent_arr));
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}

uint mass_b(int* arr, int* arr_b, uint n)
{
    uint t = 0;
    for (uint i = 0; i < n; i++, arr++)
    {
        if (!((*arr / 10) % 10))
        {
            *arr_b++ = *arr;
            t++;
        }
    }
    return t;
}