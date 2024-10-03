/* Максимум и минимум
   Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0
   Результат работы
   4 10 8 -10
   Входные данные
   1 2 3 4 5 6 7 8 9 10
   Результат работы
   10 10 1 1
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
int min(int* arr, uint n);
int max(int* arr, uint n);
int posmin(int* arr, uint n);
int posmax(int* arr, uint n);

int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%d ", posmax(data_a, size_ent_arr));
    printf("%d ", max(data_a, size_ent_arr));
    printf("%d ", posmin(data_a, size_ent_arr));
    printf("%d ", min(data_a, size_ent_arr));
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

int min(int* arr, uint n)
{
    int data = *arr++, i;
    for (i = 1; i < n; i++, arr++)
    {
        if (data > *arr)
            data = *arr;
    }
    return data;
}

int max(int* arr, uint n)
{
    int data = *arr++, i;
    for (i = 1; i < n; i++, arr++)
        if (data < *arr)
            data = *arr;
    return data;
}

int posmin(int* arr, uint n)
{
    int data = *arr++,i , p_m = 1;
    for (i = 1; i < n; i++, arr++)
        if (data > *arr)
        {
            data = *arr;
            p_m = i + 1;
        }
    return p_m;
}

int posmax(int* arr, uint n)
{
    int max = *arr++, i , p_M = 1;
    for (i = 1; i < n; i++, arr++)
        if (max < *arr)
        {
            max = *arr;
            p_M = i + 1;
        }
    return p_M;
}
