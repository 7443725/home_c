/* Пропущенное число
   В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.
   Формат входных данных
   Последовательность целых чисел от M до N. M, N не превосходит 1000.
   Формат результата
   Одно целое число
   Примеры
   Входные данные
   2   3   1   4   7   6   9   8  10   0
   Результат работы
   5
   Входные данные
   41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
   Результат работы
   35

*/

#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 1000
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
void output(int size, int a[]);
int number(int size, int a[]);
int min(int* arr, uint n);
int max(int* arr, uint n);
void sort_mass_up(int* arr, uint n);

int main()
 {
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    sort_mass_up(data_a, --i);
    printf("%d ", number(i, data_a));
    return 0;
}

int input(int a[])
{
    int i = 0, fl = 0, c = 0, data[6] = { 0 }, neg = 1;
    while (c != '\n' && i < size_arr)
    {
        c = getchar();
        if ((c != ' ' && c != '\n' && c != '-'))
            data[fl++] = c;
        else if (c == ' ' || c == '\n')
        {
            for (uint n = 0; n < fl; n++)
            {
                if (fl > 1)
                    a[i] *= 10;
                a[i] += data[n] - '0';
            }
            a[i] *= neg;
            i++;
            fl = 0;
            neg = 1;
        }
        else if (c == '-')
            neg = -1;
    }
    return i;
}

void output(int size, int a[])
{
    while (size--)
        printf("%d ", *a++);
}

#endif

int number(int size, int a[])
{
    int minn = 0, maxx = 0, data = 0;
    minn = min(a, size);
    maxx = max(a, size);
    for (int i = minn; i <= maxx; i++, a++)
        if (i != *a)
            data = i++;
    return data;
}

int min(int* arr, uint n)
{
    int data = *arr++, i;
    for (i = 1; i < n; i++, arr++)
    {
        if (data > *arr)
            data = *arr;
    }
    return data;
}

int max(int* arr, uint n)
{
    int data = *arr++, i;
    for (i = 1; i < n; i++, arr++)
        if (data < *arr)
            data = *arr;
    return data;
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