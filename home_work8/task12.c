/* По убыванию и по возрастанию
   Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.
   Примеры
   Входные данные
   14  25  13  30  76  58  32  11  41  97
   Результат работы
   13  14  25  30  76  97  58  41  32  11
   Входные данные
   5 4 3 2 1 6 7 8 9 10
   Результат работы
   1 2 3 4 5 10 9 8 7 6
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
void sort_mass_up(int* arr, uint n);
void sort_mass_down(int* arr, uint n);

int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    sort_mass_up(data_a, size_ent_arr / 2);
    sort_mass_down(data_a+5, size_ent_arr / 2);
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

void sort_mass_up(int* arr, uint n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                SWAP(t, arr[j], arr[j - 1]);
            }
        }
    }
}

void sort_mass_down(int* arr, uint n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                SWAP(t, arr[j], arr[j - 1]);
            }
        }
    }
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}