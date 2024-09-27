/* Проверка на простоту
   Дано натуральное число n ≥ 1. 
   Проверьте, является ли оно простым. 
   Программа должна вывести слово YES, если число простое или NO в противном случае. 
   Необходимо составить рекурсивную функцию и использовать ее.
   int is_prime(int n, int delitel)
   Формат входных данных
   Натуральное число
   Формат результата:
   YES или NO
   Примеры:
   Входные данные:
   11
   Результат работы:
   YES
   Входные данные:
   12
   Результат работы:
   NO
   Входные данные:
   73
   Результат работы:
   YES
*/

#include <stdio.h>
typedef unsigned int uint;
int is_prime(int n, int divider);

int main(int argc, char** argv)
{
    int data_a;
    scanf("%d", &data_a);
    is_prime(data_a, 2) ? printf("YES") : printf("NO");
    return 0;
}

 
int is_prime(int n, int divider)
{
    if (n == divider)
        return 1;
    if ((n > 1) && (n % divider != 0))
        return is_prime(n, divider + 1); 
    else 	
        return 0;    	
}

