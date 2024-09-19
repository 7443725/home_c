/* Квадраты чисел
   Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.
   Формат входных данных:
   Два целых числа по модулю не больше 100
   Формат результата:
   Квадраты чисел от a до b.
   Примеры:
   Входные данные:
   4 5
   Результат работы:
   16 25
   Входные данные:
   1 5
   Результат работы:
   1 4 9 16 25
*/

#include <stdio.h>
#define MAX_DATA 100

int main (int argc, char **argv) 
{
    int data_a,data_b;
    scanf("%d%d",&data_a,&data_b);
    if(!(data_a<=data_b))
        return 0;
    for(int i = data_a;i <= data_b && i <= MAX_DATA;i++)
        printf("%d ",i*i); 
    return 0;   
}