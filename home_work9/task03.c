/* Цифры по возрастанию
   Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
   Формат входных данных
   Натуральное число не более 1000 цифр
   Формат результата
   Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.
   Примеры
   Входные данные
   54321
   Результат работы
   1 1
   2 1
   3 1
   4 1
   5 1
   Входные данные
   22443344
   Результат работы
   2 2
   3 2
   4 4
*/


#include <stdio.h>
#define size_arr 1000
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
void output(int size, int a[]);
void sort_mass_up(int* arr, uint n);


int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    sort_mass_up(data_a, i);
    output(i, data_a);
    return 0;
}

int input(int a[])
{
    int i = 0, c = 0;
    while (c != '\n' && i < size_arr)
    {
        c = getchar();
        if (c != '\n')
            a[i++] = c;
    }
    return i;
}

void output(int size, int a[])
{
    int count[size_arr] = {0},tmp = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (a[i] == a[j])
                count[i]++;
    for (int x = 0, y = 0; size--; x++, y++)
    {
        if(tmp != a[x])
             printf("%c %d\n", a[x], count[y]);
        tmp = a[x];
    }
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