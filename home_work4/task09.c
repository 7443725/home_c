/* В порядке возрастания
   Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
   Формат входных данных:
   Три целых числа
   Формат результата:
   Одно слово YES или NO
   Примеры:
   Входные данные:
   4 5 17
   Результат работы:
   YES
*/


#include <stdio.h>

int main (int argc, char **argv) 
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (a < b && b < c)
        printf("YES");
    else
        printf("NO");
    //(a < b && b < c)?printf("YES"):printf("NO");   
    return 0; 
}