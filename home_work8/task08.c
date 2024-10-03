/* Инверсия каждой трети
   Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
   Формат входных данных
   12 целых чисел через пробел
   Формат результата
   12 целых чисел через пробел
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0 5 7
   Результат работы
   10 3 -5 4 -10 8 -6 -4 7 5 0 1
   Входные данные
   1 2 3 4 5 6 7 8 9 10 11 12
   Результат работы
   4 3 2 1 8 7 6 5 12 11 10 9
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 12
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void inmass(int* arr, uint n);
void output(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    for (int i = 0; i < 3; i++)
        inmass(data_a + i * size_ent_arr / 3, size_ent_arr / 3);
    output(data_a, size_ent_arr);
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

void inmass(int* arr, uint n)
{
     for (int i = 0, j = n - 1; i < j; i++, j--)
     {
         int t = arr[i];
         arr[i] = arr[j];
         arr[j] = t;
     }
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}