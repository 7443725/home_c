/* Вычислить sin
   Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
   sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
   float sinus(float x)
   Формат входных данных:
   Одно число от 0 до 90
   Формат результата:
   Вещественное число в формате "%.3f"
   Примеры:
   Входные данные:
   45
   Результат работы:
   0.707
   Входные данные:
   30
   Результат работы:
   0.500
   Входные данные:
   0
   Результат работы:
   0.000
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
const float PI = 3.1415926535;
double sinus(double x);

int main(int argc, char** argv)
{
    double data_a;
    scanf("%lf", &data_a);
    if (data_a >= 0 && data_a <= 90)
    {
        data_a *= PI / 180.0;
        printf("%.3f", sinus(data_a));
    }
    return 0;
}

double sinus(double x)
{
    double Xn = x;
    double summ = 0.0;
    int i = 1;
    do
    {
        summ += Xn;
        Xn *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    } while (fabs(Xn) > 0.001);
    return summ;
}
