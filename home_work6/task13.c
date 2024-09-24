/* Вычислить cos
   Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
   cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)
   float cosinus(float x)
   Формат входных данных:
   Целое число от 0 до 90
   Формат результата:
   Вещественное число в формате "%.3f"
   Примеры:
   Входные данные:
   60
   Результат работы:
   0.500
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
const float PI = 3.1415926535;
double cos_x(double x);

int main(int argc, char** argv)
{
    double data_a;
    scanf("%lf", &data_a);
    if (data_a >= 0 && data_a <= 90)
    {
        data_a *= PI / 180.0;
        printf("%.3f", cos_x(data_a));
    }
    return 0;
}

double cos_x(double x)
{
    double res = 1;
    double sign = 1, fact = 1, pow = 1;
    for (int i = 1; i < 5; i++) 
    {
        sign = sign * -1;
        fact = fact * (2 * i - 1) * (2 * i);
        pow = pow * x * x;
        res = res + sign * pow / fact;
    }

    return res;
}