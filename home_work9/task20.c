/* Четные и нечетные
   Дан целочисленный массив из 10 элементов.
   Необходимо определить количество четных и нечетных чисел.
   Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.
   Формат входных данных
   10 целых чисел через пробел
   Формат результата
   10 целых чисел через пробел
   Примеры
   Входные данные
   48 31 20 61 97 12 18 100 200 123
   Результат работы
   48 3 20 1 63 12 18 100 200 3
   Входные данные
   48 25 57 34 23 91 90 85 30 79
   Результат работы
   32 25 57 4 23 91 0 85 0 79
*/

#include <stdio.h>
#define SIZE 10

void input(int n,int a[]);
void output(int n, int a[]);
void even_odd(int n,int a[]);
int digits(int number);

int main(void)
{
    int data_a[SIZE] = { 0 };
    input(SIZE, data_a);
    even_odd(SIZE, data_a);
    output(SIZE, data_a);
    return 0;
}

void input(int n, int a[])
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);  
}

void output(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void even_odd(int n, int a[])
{
    int fl_ev = 0, fl_od = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2)
            fl_od++;
        else
            fl_ev++;
    if (fl_ev > fl_od)
    {
        for (int i = 0; i < n; i++)
            if (a[i] % 2)
                a[i] = digits(a[i]);
    }
    else if (fl_ev <= fl_od)
    {
        for (int i = 0; i < n; i++)
            if (!(a[i] % 2))
                a[i] = digits(a[i]);
    }
    
}

int digits(int number)
{
    int m = 1;
    if(number % 2)
        while (number)
        {
             if ((number % 10) % 2 != 0)
             {
                 m *= (number % 10);
             }
        number /= 10;
        }
    else
        while (number)
        {
            if ((number % 10) % 2 == 0)
            {
                m *= (number % 10);
            }
            number /= 10;
        }

    return m;
}