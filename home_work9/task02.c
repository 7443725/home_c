/* Четные в начало
   Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.
   void sort_even_odd(int n, int a[])
   Формат входных данных
   Функцийя принмате на вход целые числа
   Формат результата
   Отсортированный исходный массив
   Примеры
   Входные данные
   20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
   Результат работы
   20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
   Входные данные
   1 0 1 0 1
   Результат работы
   0 0 1 1 1
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 100
typedef unsigned int uint;
int input(int a[]);
void sort_array(int size, int a[]);
void output(int size, int a[]);
void sort_even_odd(int n, int a[]);

int main()
{
    int data_a[size_arr] = { 0 },i = 0;
    i = input(data_a);
    //sort_array(i, data_a);
    sort_even_odd(i, data_a);
    output(i, data_a);
    return 0;
}

int input(int a[])
{
    int i = 0, fl = 0, c = 0, data[6] = { 0 },neg = 1;
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

void sort_array(int size, int a[])
{
    for (int b = 0; b < size; ++b)
    {
        for (int j = b; j < size; ++j)
        {
            if (a[b] > a[j])
            {
                int temp = a[b];
                a[b] = a[j];
                a[j] = temp;
            }
        }
    }
}
#endif

void sort_even_odd(int n, int a[])
{
    int tmp;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            tmp = a[j];
            if (tmp % 2 != 0 && a[j + 1] % 2 == 0)
            {
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

