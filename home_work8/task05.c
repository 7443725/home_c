/* Сумма положительных элементов
   Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   Одно целое число - сумма положительных элементов массива
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0
   Результат работы
   26
   Входные данные
   1 -2 3 -4 5 -6 7 -8 9 0
   Результат работы
   25
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
uint sumposit(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%d ", sumposit(data_a, size_ent_arr));
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

uint sumposit(int* arr, uint n)
{
    int data = 0;
    for (uint i = 0; i < n; i++, arr++)
        if (*arr > 0)
            data += *arr;
    return data;
}