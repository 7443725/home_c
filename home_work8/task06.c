/* Среднее арифметическое массива
   Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.
   Формат входных данных
   12 целых чисел через пробел
   Формат результата
   Среднее арифметическое в формате "%.2f"
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0 5 7
   Результат работы
   1.08
   Входные данные
   1 2 3 4 5 6 7 8 9 10 11 12
   Результат работы
   6.50
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 12
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
float arithmetic_mean(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%.2f ", arithmetic_mean(data_a, size_ent_arr));
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