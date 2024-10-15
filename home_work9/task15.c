/* Больше по модулю
   Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент.
   Прототип функции int count_bigger_abs(int n, int a[]);
   Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
   Формат входных данных
   Функция получает размер массива и массив целых чисел
   Формат результата
   Функция возвращает целое число равное количеству элементов превосходящих по модулю максимальный элемент.
   Примеры
   Входные данные
   1 -20 3 4 -50 6 7 8 9 10
   Результат работы
   2
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
int count_bigger_abs(int n, int a[]);



int main()
{
    int data_a[size_arr] = { 0 }, i = 0, f = 0, t = 0;
    i = input(data_a);
    printf("%d ", count_bigger_abs(i, data_a));
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

int count_bigger_abs(int n, int a[])
{
    int max = -2147483647;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }

    int counter = 0, dat = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            dat = -1 * a[i];
        else 
            dat = a[i];
        if (dat > max)
            counter++;
    }
    return counter;
}
