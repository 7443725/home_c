/* Сумма в интервале
   Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
   Прототип функции int sum_between_ab(int from, int to, int size, int a[])
   Формат входных данных
   Функция принимает концы отрезка from и to, размер массива, массив целых чисел
   Формат результата
   Функция возвращает сумму элементов в интервале [from, to]
   Примеры
   Входные данные
   4 6 1 2 3 4 5 6 7 8 9 10
   Результат работы
   15
   Входные данные
   6 4 1 2 3 4 5 6 7 8 9 10
   Результат работы
   15
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
int sum_between_ab(int from, int to, int size, int a[]);



int main()
{
    int data_a[size_arr] = { 0 }, i = 0, f = 0, t = 0;
    i = input(data_a);
    scanf_s("%d %d", &f, &t);
    printf("%d ", sum_between_ab(f, t, i, data_a));
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

int sum_between_ab(int from, int to, int size, int a[])
{
    int summ = 0, fl = 0;
    for (int i = 0; i < size; i++, a++)
        if (from <= *a && *a <= to || from >= *a && *a >= to)
            summ += *a;
    return summ;
}
