/* В прямом порядке
   Дано натуральное число N.
   Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками.
   Необходимо реализовать рекурсивную функцию.
   void print_num(int num)
   Формат входных данных:
   Одно целое неотрицательное число
   Формат результата:
   Все цифры числа через пробел в прямом порядке.
   Примеры:
   Входные данные:
   15
   Результат работы:
   1 5
   Входные данные:
   54321
   Результат работы:
   5 4 3 2 1
*/

#include <stdio.h>
typedef unsigned int uint;
void print_num(uint);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    if (!data_a)
    {
        printf("%d ", data_a);
        return 0;
    }
    print_num(data_a);
    return 0;
}

void print_num(uint a)
{ 
    uint b = 0;
    if (a)
    {
        b = a % 10;
        a /= 10;
        print_num(a);
        printf("%d ", b);
    }
}