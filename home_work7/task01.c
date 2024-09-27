/* От 1 до N
   Составить рекурсивную функцию, печать всех чисел от 1 до N
   Формат входных данных:
   Одно натуральное число
   Формат результата:
   Последовательность чисел от 1 до введенного числа
   Примеры:
   Входные данные:
   5
   Результат работы:
   1 2 3 4 5
*/

#include <stdio.h>
typedef unsigned int uint;
void one_to_n(uint);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    one_to_n(data_a);
    return 0;
}

void one_to_n(uint a)
{
    if (a != 1)
        one_to_n(a - 1);
    printf("%d ", a);
}