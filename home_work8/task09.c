/* Циклический сдвиг массива вправо
   Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически
   Примеры
   Входные данные
   4   -5   3  10  -4  -6  8  -10  1  0
   Результат работы
   0   4   -5   3  10  -4  -6  8  -10  1
   Входные данные
   1 2 3 4 5 6 7 8 9 10
   Результат работы
   10 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void shift_mass(int* arr, uint n);
void output(int* arr, uint n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    shift_mass(data_a, size_ent_arr);
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

void shift_mass(int* arr, uint n)
{
    int temp = arr[--n];
    while (n > 0)
        arr[n--] = arr[n - 1];
    *arr = temp;
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}