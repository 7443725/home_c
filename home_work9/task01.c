/* Сортировка по взрастанию
   Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
   Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
   Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.
   Формат входных данных
   Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
   Формат результата
   Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.
   Примеры
   Входные данные
   20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
   Результат работы
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
   Входные данные
   5 4 3 2 1
   Результат работы
   1 2 3 4 5
*/
/*
#include <stdio.h>
#define size_arr 100
typedef unsigned int uint;
int input(int a[]);
void sort_array(int size, int a[]);
void output(int size, int a[]);

int main()
{
    int data_a[size_arr] = { 0 },i = 0;
    i = input(data_a);
    sort_array(i, data_a);
    output(i, data_a);
    return 0;
}

int input(int a[])
{
    int i = 0, fl = 0, c = 0, data[6] = { 0 };
    while (c != '\n' && i < size_arr)
    {
        c = getchar();
        if (c != ' ' && c != '\n')
            data[fl++] = c;
        else if (c == ' ' || c == '\n')
        {
            for (uint n = 0; n < fl; n++)
            {
                if (fl > 1)
                    a[i] *= 10;
                a[i] += data[n] - '0';
            }
            i++;
            fl = 0;
        }
    }
    return i;
}*/

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
/*
void output(int size, int a[])
{
    while (size--)
        printf("%d ", *a++);
}*/

