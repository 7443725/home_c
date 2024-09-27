/* От 1 до N
   Составить рекурсивную функцию, печать всех чисел от N до 1.
   Формат входных данных:
   Одно натуральное число
   Формат результата:
   Последовательность целых чисел от введенного числа до 1, через пробел.
   Примеры:
   Входные данные:
   5
   Результат работы:
   5 4 3 2 1
*/

#include <stdio.h>
typedef unsigned int uint;
void reverse_n_one(uint n);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    reverse_n_one(data_a);
    return 0;
}

void reverse_n_one(uint n)
{
    printf("%d ", n);
    if (n > 1)
        reverse_n_one(n - 1);
}