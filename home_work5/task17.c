/* Числа Фибоначчи
   Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
   Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …,
   в которой каждое последующее число равно сумме двух предыдущих.
   Формат входных данных:
   Одно натуральное число
   Формат результата:
   Ряд чисел Фибоначчи через пробел
   Примеры:
   Входные данные:
   5
   Результат работы:
   1 1 2 3 5
   Входные данные:
   10
   Результат работы:
   1 1 2 3 5 8 13 21 34 55
   */

#include <stdio.h>
typedef unsigned int uint;

void fib(int n, int prev1, int prev2);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    if (data_a < 1)
        return 0;
    else 
        fib(data_a, 0, 1);
    
    return 0;
}

void fib(int n, int prev1, int prev2)
{
    if (n < 1) {
        return;
    }
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    printf("%d ", curr);
    return fib(n - 1, prev1, prev2);
}