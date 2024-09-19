/* Ровно три цифры
   Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
   Формат входных данных:
   Целое положительное число
   Формат результата:
   Одно слов: YES или NO
   Примеры:
   Входные данные
   123
   Результат работы
   YES
   Входные данные
   1234
   Результат работы
   NO
*/

#include <stdio.h>

int main (int argc, char **argv) 
{
    unsigned int data_a,count = 0;
    scanf("%d",&data_a);
    while(data_a /= 10)
        count++;
    if(count == 2)
        printf("YES");
    else
        printf("NO");
    return 0;   
}