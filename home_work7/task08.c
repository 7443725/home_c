/* От A до B
   Составить рекурсивную функцию, Выведите все числа от A до B включительно,
   в порядке возрастания, если A < B, или в порядке убывания в противном случа.
   Формат входных данных:
   Два целых числа через пробел.
   Формат результата:
   Последовательность целых чисел.
   Примеры:
   Входные данные:
   5 2
   Результат работы:
   5 4 3 2
   Входные данные:
   2 7
   Результат работы:
   2 3 4 5 6 7
*/

#include <stdio.h>
typedef unsigned int uint;
void rev(int, int);

int main(int argc, char** argv)
{
    int data_a, data_b;
    scanf("%d%d", &data_a, &data_b);
    rev(data_a, data_b);
    return 0;
}

void rev(int a, int b)
{
    if (a >= b)
    {
        printf("%d ", a);
        if (a > b)
            rev(a - 1,b);
    }
    else if (a < b)
    {
        if (a < b)
            rev(a ,b - 1);
        printf("%d ", b);
    }
}