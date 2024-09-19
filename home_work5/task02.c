/* Сумма квадратов маленьких чисел
   Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
   Формат входных данных:
   Два целых числа по модулю не больше 100
   Формат результата:
   Сумма квадратов от первого введенного числа до второго
   Примеры:
   Входные данные:
   4 10
   Результат работы:
   371
   Входные данные:
   1 5
   Результат работы:
   55
*/

#include <stdio.h>
#define MAX_DATA 100

int main (int argc, char **argv) 
{
    unsigned int summ = 0;
    int data_a,data_b;
    scanf("%d%d",&data_a,&data_b);
    if(!(data_a<=data_b))
        return 0;
    for(int i = data_a;i <= data_b && i <= MAX_DATA;i++)
        summ += i*i;
    printf("%d ",summ);
    return 0;   
}