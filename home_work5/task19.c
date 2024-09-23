/* Проверка на простоту
   Проверить число на простоту.
   Формат входных данных:
   Натуральное число
   Формат результата:
   Если число является простым напечатать YES, иначе NO
   Примеры:
   Входные данные:
   10
   Результат работы:
   NO
   Входные данные:
   7
   Результат работы:
   YES
   */

#include <stdio.h>
typedef unsigned int uint;

int main(int argc, char** argv)
{
    uint data_a;
    scanf("%d", &data_a);
    if (data_a > 1)
    {
        for (uint i = 2; i < data_a; i++)
            if (data_a % i == 0)
            {
                printf("NO");
                return 0;
            }
            printf("YES");
    }
    else
        printf("NO");
    return 0;
}