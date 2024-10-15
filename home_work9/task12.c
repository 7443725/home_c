/* Поменять местами
   Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
   Прототип функции void change_max_min(int size, int a[])
   Формат входных данных
   Функция принимает на вход размер массива и массив чисел типа int
   Формат результата
   Функция не возвращает значения, измененный массив сохраняется на месте исходного.
   Примеры
   Входные данные
   1 2 3 4 5 6 7 8 9 10
   Результат работы
   10 2 3 4 5 6 7 8 9 1
*/

//#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 200
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int input(int a[]);
void change_max_min(int size, int a[]);


int main()
{
    int data_a[size_arr] = { 0 }, i = 0;
    i = input(data_a);
    change_max_min(i, data_a);
    for(int n = 0; n < i; n++)
        printf("%d ", data_a[n]);
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

void change_max_min(int size, int a[])
{
      int data = a[0],p_m = 0;
      for (int i = 1; i < size; i++)
          if (data > a[i])
          {
              data = a[i];
              p_m = i;
          }
      int max = a[0],p_M = 0;
      for (int n = 1; n < size; n++)
          if (max < a[n])
          {
              max = a[n];
              p_M = n;
          }
    int t = 0;
     t = a[p_m];
     a[p_m] = a[p_M]; 
     a[p_M] = t; 
}

