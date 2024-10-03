/* Положительные и отрицательные
   Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
   Формат входных данных
   10 целых чисел через пробел.
   Формат результата
   Сперва положительные числа, потом отрицательыне числа, через пробел.
   Примеры
   Входные данные
   5 -4 0 1 4 -3 -3 3 0 2
   Результат работы
   5 1 4 3 2 -4 -3 -3
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr_pos, int* arr_neg, uint n);
void select(int* arr, int* arr_pos, int* arr_neg, int n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 }, data_p[size_arr] = { 0 }, data_n[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    select(data_a, data_p, data_n, size_ent_arr);
    output(data_p, data_n, (size_ent_arr / 2)-1);
    return 0;
}

uint entr_data(int* arr, uint n)
{
    uint i = 0;
    for (; i < size_ent_arr && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}

void output(int* arr_pos, int* arr_neg, uint n)
{
    while (*arr_pos)
        printf("%d ", *arr_pos++);
    while (*arr_neg)
        printf("%d ", *arr_neg++);
}

void select(int* arr, int* arr_pos, int* arr_neg, int n)
{
    for (uint i = 0; i < n; i++, arr++)
    {
        if (*arr > 0)
            *arr_pos++ = *arr;
        else if (*arr < 0)
            *arr_neg++ = *arr;
    }
}