/* Два максимума
   Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
   Формат входных данных
   10 целых чисел через пробел.
   Формат результата
   Сумма двух максимальных элементов.
   Примеры
   Входные данные
   4 -5 3 10 -4 -6 8 -10 1 0
   Результат работы
   18
   Входные данные
   1 2 3 4 5 6 7 8 9 10
   Результат работы
   19
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
int summmax(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    printf("%d ", summmax(data_a, size_ent_arr));
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

int summmax(int* arr, uint n)
{
    int max_1 = 0, max_2 = 1, i;
    for (i = 1; i < 10; i++)
    {
        if (arr[i] > arr[max_1])
        {
            max_2 = max_1;
            max_1 = i;
        }
        else if (arr[i] > arr[max_2])
            max_2 = i;
    }
    return arr[max_1] + arr[max_2];
}