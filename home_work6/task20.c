/* Скобки
   Проверить строку состоящую из скобок "(" и ")" на корректность.
   Формат входных данных:
   На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'.
   Размер строки не более 1000 символов.
   Формат результата:
   Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае.
   Примеры:
   Входные данные:
   (()()).
   Результат работы:
   YES
   Входные данные:
   ()(.
   Результат работы:
   NO
*/

#include <stdio.h>
#include <math.h>
typedef unsigned int uint;
uint staples();

int main(int argc, char** argv)
{
    staples() ? printf("YES") : printf("NO");
    return 0;
}

uint staples()
{
    char c = '0';
    int data_a = 1000, fl_data_a = 0;
    while (c != '.')
    {
        scanf("%c", &c);
        if (c == '(')
        {
            if (!fl_data_a & (1<<0))
                fl_data_a |= (1<<0)|(1<<1);
            data_a++;
        }
        else if (c == ')')
        {
            if (!fl_data_a & (1 << 0))
                fl_data_a |= (1 << 0);
            data_a--;
        }
    }
    if (fl_data_a & (1 << 1) && data_a == 1000)
        return 1;
    return 0;
}