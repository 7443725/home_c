/* Клетки
   Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов, например, черного и белого (см. рисунок).
   Каждая клетка имеет координату, состоящую из буквы и цифры.
   Горизонтальное расположение клетки определяется буквой от A до H, а вертикальное – цифрой от 1 до 8.
   Заметим, что клетка с координатой А1 имеет черный цвет. Требуется по заданной координате определить цвет клетки.

   Формат входных данных
   В единственной строке входного файла записана координата клетки на шахматной доске: всего два символа – буква и цифра (без пробелов).
   Формат результата
   В выходной файл нужно вывести «WHITE», если указанная клетка имеет белый цвет и «BLACK», если она черная.
   Примеры
   Входные данные
   C3
   Результат работы
   BLACK
   Входные данные
   G8
   Результат работы
   WHITE
*/

#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#define size_arr 2
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
int Input(int len, char arr[]);
const char* chess(char a[]);



int main()
{
    char data_a[size_arr] = { 0 };
    Input(size_arr,data_a);
    printf("%s", chess(data_a));
    return 0;
}

int Input(int len, char arr[])
{
    char input;
    int count = 0;
    while (count < len)
    {
        scanf("%c", &input);
        if (input == '\n')
            return count;
        arr[count++] = input;
    }
    return count;
}

#endif

const char* chess(char a[])
{
    int x = 0, y = 0;
    x = *a - 'A';
    y = (*(++a) - '0') - 1;
    return (x + y % 2) % 2 == 0 ? "BLACK" : "WHITE";
}


