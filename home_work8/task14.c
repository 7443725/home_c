/* Более одного раза
   Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более
   одного раза. В результирующем массиве эти числа не должны повторяться.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
   Примеры
   Входные данные
   4 1 2 1 11 2 34 8 9 10
   Результат работы
   1 2
   Входные данные
   1 2 3 4 5 1 2 3 4 5
   Результат работы
   1 2 3 4 5
   Входные данные
   1 1 1 1 1 1 1 1 1 1
   Результат работы
   1
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
int select(int arr[], int arr_b[], int n);


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

int select(int arr[], int arr_b[], int n)
{
    int count = 0;
    int fl = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
            {
                for (int k = 0; k < count; k++)
                {
                    if (arr_b[k] == arr[i])
                    {
                        fl = 0;
                        break;
                    }
                    else
                        fl = 1;
                }
                if (fl == 1)
                    arr_b[count++] = arr[i];
            }
    return count;
}
