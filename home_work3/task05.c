/* Сумма цифр
   На вход подается произвольное трехзначное число, напечать сумму цифр
   Формат входных данных:
   Трехзначное целое положительное число
   Формат результата:
   Одно целое число
   Примеры:
   Входные данные:
   435
   Результат работы:
   12
   Входные данные:
   100
   Результат работы:
   1 
*/


#include <stdio.h>

int main (int argc, char **argv) 
{
    int a,b,c;
    scanf(" %d", &a);
    b = a / 100;
    a %= 100;
    c = a / 10;
    a %= 10;  
    printf("%d\n",a+b+c);
    return 0; 
}