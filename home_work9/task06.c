/* Два одинаковых
   Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
   int is_two_same(int size, int a[]);
   Формат входных данных
   Массив из целых чисел
   Формат результата
   Функция возвращает 1 или 0
   Примеры
   Входные данные
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
   Результат работы
   NO
   Входные данные
   1 2 1 4 5
   Результат работы
   YES
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
typedef unsigned int uint;
int input(int a[]);
int is_two_same(int size, int a[]);

int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    printf("%d ", is_two_same(i, data_a));
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

int is_two_same(int size, int a[])
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size - 1; j++)
        {
            if (a[i] == a[j + 1])
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}