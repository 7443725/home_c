/* Чаще других
   Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
   Формат входных данных
   10 целых числе через пробел
   Формат результата
   Одно число, которое встречается чаще других.
   Примеры
   Входные данные
   4  1  2  1  11  2  34  11  0  11
   Результат работы
   11
*/

#include <stdio.h>
#define size_arr 20
#define size_ent_arr 10
typedef unsigned int uint;
uint entr_data(int* arr, uint n);
void output(int* arr, uint n);
int select(int* arr,int n);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 };
    entr_data(data_a, size_arr);
    
    printf("%d ", select(data_a, size_ent_arr));
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

int select(int* arr, int n)
{
    int maxcount = 1, nn = -1;
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (maxcount < count)
        {
            maxcount = count;
            nn = i;
        }
    }
    return arr[nn];
}
