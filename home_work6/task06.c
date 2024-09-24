/* Сколько зерен на доске
   Когда создатель шахмат, древнеиндийский мудрец и математик Сисса бен Дахир, показал своё изобретение Правителю страны, тому так понравилась игра, что он позволил изобретателю право самому выбрать награду.
   Мудрец попросил у Повелителя за первую клетку шахматной доски заплатить ему одно зерно риса, за второе — два, за третье — четыре и т. д., удваивая количество зёрен на каждой следующей клетке.
   Помоги повелителю сосчитать сколько зерен на какой клетке лежит.
   Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
   Формат входных данных
   Цлое число от 1 до 64
   Формат результата
   Одно целое число. Количество зерен на данной клетке.
   Примеры:
   Входные данные:
   3
   Результат работы:
   4
   Входные данные:
   28
   Результат работы:
   134217728
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
typedef unsigned long long ull;
ull SUMM(uint x);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    printf("%llu ", SUMM(data_a));
    return 0;
}

ull SUMM(uint x)
{
    ull summ = 1;
    for (uint i = 2; i <= x; i++)
        summ *= 2;
    return summ;
}

