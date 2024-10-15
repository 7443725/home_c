/* В заданном интервале
   Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
   Прототип функции int count_between(int from, int to, int size, int a[])
   Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
   Формат входных данных
   Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
   Формат результата
   Функция возвращает целое число - количество числе в интервале [from, to]
   Примеры
   Входные данные
   4 6 1 2 3 4 5 6 7 8 9 10
   Результат работы
   3
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
int count_between(int from, int to, int size, int a[]);



int main()
{
    int data_a[size_arr] = { 0 }, i = 0,f = 0, t = 0;
    i = input(data_a);
    scanf_s("%d %d", &f,&t);
    printf("%d ", count_between(f, t, i, data_a));
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

int count_between(int from, int to, int size, int a[])
{
    int count = 0,fl = 0;
    for (int i = 0; i < size; i++, a++)
        if (from <= *a && *a <= to)
            count++;
    return count;
}
