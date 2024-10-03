/* Инверсия половинок
   Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом.
   Формат входных данных
   10 целых элементов массива через пробел.
   Формат результата
   10 целых элементов массива через пробел.
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0
   Результат работы
   -4 10 3 -5 4 0 1 -10 8 -6
   Входные данные
   1 2 3 4 5 6 7 8 9 10
   Результат работы
   5 4 3 2 1 10 9 8 7 6
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void inmass(int* arr, uint n);
void output(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    inmass(data_a, size_ent_arr);
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
    int data = 0;
    for (uint i = 0, j = 4; i < 3; i++, j--)
    {
        data = arr[i];
        arr[i] = arr[j];
        arr[j] = data;
    }
    for (uint i = 5, j = 9; i < 8; i++, j--)
    {
        data = arr[i];
        arr[i] = arr[j];
        arr[j] = data;
    }
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}