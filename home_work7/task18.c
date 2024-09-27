/* Цифры слева направо
   Написать рекурсивную функцию и используя ее решить задачу.
   Напечатать цифры введенного натурального числа в порядке следования(слева направо) через пробел.
   void print_digits(int n)
   Формат входных данных:
   Натуральное число
   Формат результата:
   Последовательность цифр в слева направо через пробел
   Примеры:
   Входные данные:
   12345
   Результат работы:
   1 2 3 4 5
   Входные данные:
   709
   Результат работы:
   7 0 9
*/

#include <stdio.h>
typedef unsigned int uint;
void print_digits(int n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    print_digits(data_a);
    return 0;
}

void print_digits(int n)
{   
    if (n)
        print_digits(n / 10);
    if (n)
    printf("%d ", n % 10);
}