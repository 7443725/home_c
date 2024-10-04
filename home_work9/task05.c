/* Максимум в массиве
   Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
   Прототип функции: int find_max_array(int size, int a[])
   Формат входных данных
   Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
   Формат результата
   Одно целое число
   Примеры
   Входные данные
   773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3
   Результат работы
   983
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
typedef unsigned int uint;
int input(int a[]);

int find_max_array(int size, int a[]);

int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    find_max_array(i, data_a);
    printf("%d " ,find_max_array(i, data_a));
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

int find_max_array(int size, int a[])
{
    int max = *a;
    for (int i = 1; i < size; i++)
        if (a[i] > max) 
            max = a[i];
    return max;
}