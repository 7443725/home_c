/* След матрицы
   Составить функцию которая находит след матрицы в двумерном массиве.
   Показать пример ее работы на матрице из 5 на 5 элементов.
   След матрицы - это сумма элементов на главной диагонали.
   Формат входных данных
   25 целых чисел через пробел.
   Формат результата
   Одно целое число.
   Примеры
   Входные данные
   1 1 1 1 1
   2 2 2 2 2
   3 3 3 3 3
   4 4 4 4 4
   5 5 5 5 5
   Результат работы
   15
*/

#include <stdio.h>
#define COL 5
#define ROW 5

void input(int col, int row, int a[COL][ROW]);
int matrix(int col, int row, int a[COL][ROW]);


int main(void)
{
    int data_a[COL][ROW] = {0};
    input(COL, ROW, data_a);
    printf("%d\n", matrix(COL, ROW, data_a));

    return 0;
}

void input(int col, int row, int a[COL][ROW])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &a[j][i]);
        }
    }
}


int matrix(int col, int row, int a[COL][ROW])
{
    int t = 0;
    for (int i = 0; i < col; i++)
    {
        t += a[i][i];
    }
    return t;
}


