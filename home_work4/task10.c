/* Какое время года
   Ввести номер месяца и вывести название времени года.
   Формат входных данных:
   Целое число от 1 до 12 - номер месяца.
   Формат результата:
   Время года на английском: winter, spring, summer, autumn
   Примеры:
   Входные данные:
   4
   Результат работы:
   spring
   Входные данные:
   1
   Результат работы:
   winter
*/


#include <stdio.h>

int main (int argc, char **argv) 
{
    int a;
    scanf("%d",&a);
    if(a > 0 && a < 3 || a == 12)
        printf("winter");
    else if(a > 2 && a < 6)
        printf("spring");  
    else if(a > 5 && a < 9)
        printf("summer");   
    else if(a > 8 && a < 12)
        printf("autumn");

    return 0; 
}