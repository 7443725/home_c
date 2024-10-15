/* Поменять местами
   Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
   Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует.
   Если отрицательных элементов нет - массив не менять.
   Прототип функции: void swap_negmax_last(int size, int a[])
   Формат входных данных
   Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.
   Примеры
   Входные данные
   1 -2 -3 -4 5 6 7 8 9 10
   Результат работы
   1 10 -3 -4 5 6 7 8 9 -2
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
void swap_negmax_last(int size, int a[]);


int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    swap_negmax_last(i, data_a);
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

#endif

void swap_negmax_last(int size, int a[])
{
    int fl = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            fl = 1;
            break;
        }
    }
    
    if (fl)
    {
        int t = 0, tm = 0, ti = 0;
        for (int i = 0; i < size; ++i)
        {
            if (a[i] < 0)
            {
                if (tm)
                {
                    t = a[i];
                }
                else
                {
                    tm = a[i];
                    ti = i;
                    continue;
                }
                if (t > tm)
                {
                    tm = t;
                    ti = i;
                }
            }
        }
        t = a[size - 1];
        a[size - 1] = tm;
        a[ti] = t;
        /*for (int i = 0; i < size; i++)
            printf("%d ", a[i]);*/
    }
    else
    {
        /*for (int i = 0; i < size; i++)
            printf("%d ", a[i]);*/
    }
}



