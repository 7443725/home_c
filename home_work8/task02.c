/* Найти минимум
   Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
   Формат входных данных
   5 целых чисел через пробел
   Формат результата
   Одно единственное целое число
   Примеры
   Входные данные
   4 15 3 10 14
   Результат работы
   3
   Входные данные
   1 2 3 4 -5
   Результат работы
   -5
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 5
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
float arithmetic_mean(int* arr, uint n);
int min(int* arr, uint n);

int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%d  ", min(data_a, size_ent_arr));
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

float arithmetic_mean(int* arr, uint n)
{
    float data = 0;
    for (uint i = 0; i < n; i++)
        data += arr[i];
    return data /= n;
}

int min(int* arr, uint n)
{
    int data = *arr;
    for (uint i = 0; i < n; i++, arr++)
    {
        if (data > *arr)
            data = *arr;
    }
    return data;
}