/* Цифры в строке
   Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
   void print_digit(char s[])
   Формат входных данных
   Строка из английских букв, пробелов, знаков препинания и цифр
   Формат результата
   Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.
   Примеры
   Входные данные
   Hello123 world77.
   Результат работы
   1 1
   2 1
   3 1
   7 2
*/

/*
#include <stdio.h>
#define size_arr 1000
#define SWAP(t, a, b) do { t = a; a = b; b = t; } while (0);
typedef unsigned int uint;
void input(char a[]);
void print_digit(char s[]);

int main()
{
    char data_a[size_arr] = { 0 };
    input(data_a);
    print_digit(data_a);
    return 0;
}

void input(char a[])
{
    char c = 0;
    int i = 0;
    while (c != '\n' && i < size_arr)
    {
        c = getchar();
        if (c != '\n')
            a[i++] = c;
    }
}
*/
void print_digit(char s[])
{
    int data[100] = {0},n = 0;
    for (; *s != '.'; s++)
        if (*s >= '0' && *s <= '9')
            data[n++] = *s - '0';
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                t = data[j];
                data[j] = data[j - 1];
                data[j - 1] = t;
            }
        }
    }
    int count[100] = { 0 }, tmp = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (data[i] == data[j])
                count[i]++;
    for (int x = 0, y = 0; n--; x++, y++)
    {
        if (tmp != data[x])
            printf("%d %d\n", data[x], count[y]);
        tmp = data[x];
    }
}