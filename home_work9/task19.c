/* Больше среднего
   Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали.
   Реализовать функцию среднее арифметическое главной диагонали.
   Формат входных данных
   5 строк по 5 целых чисел через пробел
   Формат результата
   Одно целое число
   Примеры
   Входные данные
   1 1 1 1 1
   2 2 2 2 2
   3 3 3 3 3
   4 4 4 4 4
   5 5 5 5 5
   Результат работы
   10
*/

#include <stdio.h>
#define COL 5
#define ROW 5

void input(int col, int row, int a[COL][ROW]);
int max_matrix(int col, int row, int a[COL][ROW]);


int main(void)
{
    int data_a[COL][ROW] = { 0 };
    input(COL, ROW, data_a);
    printf("%d\n", max_matrix(COL, ROW, data_a));

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


int max_matrix(int col, int row, int a[COL][ROW])
{
    int t = 0;
    for (int i = 0; i < col; i++)
    {
        t += a[i][i];
    }
    t /= col;
    int count = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            if (t < a[j][i])
                count++;
    }
    return count;
}