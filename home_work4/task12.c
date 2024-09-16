/* Существует ли треугольник?
   Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.
   Формат входных данных
   Три целых числа. Стороны треугольника a, b, c.
   Формат результата
   YES или NO
   Примеры:
   Входные данные:
   3 2 4
   Результат работы:
   YES
*/


#include <stdio.h>
#include <stdbool.h>

bool true_triangle (int a,int b,int c)
{
    return a + b > c && a + c > b && b + c > a;
}

int main (int argc, char **argv) 
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(true_triangle(a,b,c))
        printf("YES");
    else 
        printf("NO");  
    
    return 0; 
}