/* Среднее арифметическое чисел
   Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
   Формат входных данных:
   5 целых не нулевых чисел через пробел
   Формат результата:
   Олно число в формате "%.3f"
   Примеры
   Входные данные
   4 15 3 10 14
   Результат работы
   9.200
   Входные данные
   1 2 3 4 5
   Результат работы
   3.000
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 5
typedef unsigned int uint;
uint entr_data(int* arr,uint n);
float arithmetic_mean(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%.3f ", arithmetic_mean(data_a, size_ent_arr));
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