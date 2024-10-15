/* Сумма минимальна
   Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.
   Формат входных данных
   Последовательность из 30 целых чисел через пробел
   Формат результата
   Два целых числа через пробел
   Примеры
   Входные данные
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
   Результат работы
   0 1
*/

#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
void summ_min(int size, int a[]);


int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    summ_min(i, data_a);
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

void summ_min(int size, int a[])
{
    int min_1 = 0, min_2 = 1, i;
    for (i = 1; i < size; i++)
    {
        if (a[i] < a[min_1])
        {
            min_2 = min_1;
            min_1 = i;
        }
        else if (a[i] < a[min_2])
            min_2 = i;
    }
    min_1 < min_2 ? printf("%d %d", min_1, min_2) : printf("%d %d", min_2, min_1);
}

