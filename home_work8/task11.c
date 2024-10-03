/* Отсортировать по последней цифре
   Считать массив из 10 элементов и отсортировать его по последней цифре.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   Этот же массив отсортированный по последней цифре
   Примеры
   Входные данные
   14  25  13  30  76  58  32  11  41  97
   Результат работы
   30  11  41  32  13  14  25  76  97  58
   Входные данные
   109 118 100 51 62 73 1007 16 4 555
   Результат работы
   100 51 62 73 4 555 16 1007 118 109
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
void sort_mass(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    sort_mass(data_a, size_ent_arr);
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

void sort_mass(int* arr, uint n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] % 10 < arr[j - 1] % 10)
            {
                SWAP(t,arr[j], arr[j - 1]);
            }
        }
    }

}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}