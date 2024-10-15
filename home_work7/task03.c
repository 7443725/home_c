/* В обратном порядке
   Дано целое не отрицательное число N.
   Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.
   Составить рекурсивную функцию.
   Формат входных данных:
   Одно не отрицательное целое число
   Формат результата:
   Последовательность цифр введенного числа в обратном порядке через пробел
   Примеры:
   Входные данные:
   15
   Результат работы:
   5 1
   Входные данные:
   54321
   Результат работы:
   1 2 3 4 5
*/

#include <stdio.h>
typedef unsigned int uint;
void back(uint);

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    if (data_a == 0)
    {
        printf("%d ", data_a);
        return 0;
    }
    back(data_a);
    return 0;
}

void back(uint a)
{
    if(a)
    {
        printf("%d ", (a % 10));
        a /= 10;
        back(a);
    }
}