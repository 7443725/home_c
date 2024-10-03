/* Цифры по порядку
   Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
   Формат входных данных
   Одно натуральное число N
   Формат результата
   Цифры через пробел
   Примеры
   Входные данные
   54412
   Результат работы
   5 4 4 1 2
*/

#include <stdio.h>
#define size_arr 20
typedef unsigned int uint;
void output(int* arr, uint n);
uint massiv(int data, int* arr);


int main(int argc, char** argv)
{
    int data_a[size_arr] = { 0 }, data_b;
    scanf("%d", &data_b);
    output(data_a, massiv(data_b, data_a));
    return 0;
}

void output(int* arr, uint n)
{
    while (n--)
        printf("%d ", *(arr + n));
}

uint massiv(int data, int* arr)
{
    uint count = 0;
    while (data)
    {
        *arr++ = data % 10;
        data /= 10;
        count++;
    }
    return count;
}
