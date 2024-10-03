/* Только один раз
   Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   Элементы которые встречаются только один раз через пробел
   Примеры
   Входные данные
   5   -4   0  1   4  -3  -3  3  0  2
   Результат работы
   5  -4  1  4  3  2
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
uint select(int* arr, int* arr_b, int n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 }, data_b[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    output(data_b, select(data_a, data_b, size_ent_arr));
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

uint select(int* arr, int* arr_b, int n)
{
    uint count = 0;
    for (int j, i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i != j && arr[i] == arr[j])
                break;
        if (j == n)
        {
            *arr_b++ = arr[i];
            count++;
        }
    }
    return count;
}
