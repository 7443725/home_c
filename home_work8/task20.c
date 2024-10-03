/* Переставить цифры
   Переставить цифры в числе так, что бы получилось максимальное число.
   Формат входных данных
   Одно целое не отрицательное число
   Формат результата
   Целое не отрицательное число
   Примеры
   Входные данные
   1229
   Результат работы
   9221
   Входные данные
   19
   Результат работы
   91
*/

#include <stdio.h>
#define size_arr 20
typedef unsigned int uint;
typedef int (*cmpfunc_t)(const int, const int);
void output(int* arr, uint n);
int max_number(int data, int* arr);
void sort(int* array, size_t count, int order);
int* needed_element(const int* array, const size_t count, cmpfunc_t f);
void swap(int* a, int* b);
int less_func(const int a, const int b);
int greater_func(const int a, const int b);
cmpfunc_t functions[] = { less_func, greater_func };

int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 }, data_b;
    scanf("%d", &data_b);
    printf("%d", max_number(data_b, data_a));
    return 0;
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *arr++);
}

int max_number(int data, int* arr)
{
    uint count = 0;
    int data_a = 0;
    while (data)
    {
        *arr++ = data % 10;
        data = data / 10;
        count++;
    }
    arr -= count;
    sort(arr, count, 0);
    while (count--)
    {
        data_a *= 10;
        data_a += *arr++;
    }
    return data_a;
}

void sort(int* array, size_t count, int order)
{
    if (count > 1) {
        int* ordered = needed_element(array, count, functions[order]);
        if (ordered != array)
            swap(array, ordered);
        sort(array + 1, count - 1, order);
    }
}

int* needed_element(const int* array, const size_t count, cmpfunc_t f) 
{
    return (count < 2) ? (int*)array : needed_element(array + f(array[0], array[count - 1]), count - 1, f);
}

int less_func(const int a, const int b) 
{
    return (a < b);
}

int greater_func(const int a, const int b) 
{
    return (a > b);
}

void swap(int* a, int* b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
