/* Сумма цифр числа
   Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
   int sum_digits(int n)
   Формат входных данных:
   Одно натуральное число.
   Формат результата:
   Целое число - сумма цифр введенного числа.
   Примеры:
   Входные данные:
   123
   Результат работы:
   6
   Входные данные:
   1000
   Результат работы:
   1
*/

#include <stdio.h>
typedef unsigned int uint;
int sum_digits(int n);

int main(int argc, char** argv)
{
    int data_a;
    scanf("%d", &data_a);
    printf("%d ", sum_digits(data_a));
    return 0;
}

int sum_digits(int n)
{
    static int a = 0;
    if (n)
    {
        a += n % 10;
        n /= 10;
        sum_digits(n);
    }
    return a;
}