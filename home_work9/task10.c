/* Упаковать строку
   Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>
   Формат входных данных
   Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'
   Формат результата
   Результат состоящий из букв и чисел, без пробелов
   Примеры
   Входные данные
   aaaaabbbc.
   Результат работы
   a5b3c1
   Входные данные
   zzzzzzzzzzz.
   Результат работы
   z11
   Входные данные
   aaabbbbaa.
   Результат работы
   a3b4a2
*/

#include <stdio.h>
#define SIZE 1000

int Input(int len, char arr[]);
void PrintSymbosCount(int len, char symbols[], int count[]);
int CountSymbols(int len, char arr[], char symbols[], int count[]);



int main()
{
    char buf[SIZE], symbols[SIZE];
    int count[SIZE];
    int len = Input(SIZE, buf);
    int lenCount = CountSymbols(len, buf, symbols, count);
    PrintSymbosCount(lenCount, symbols, count);
    return 0;
}

int Input(int len, char arr[])
{
    char input;
    int count = 0;
    while (count < len)
    {
        scanf("%c", &input);
        if (input == '.')
            return count;
        arr[count++] = input;
    }
    return count;
}

void PrintSymbosCount(int len, char symbols[], int count[])
{
    for (int i = 0; i < len; i++)
        printf("%c%d", symbols[i], count[i]);
    printf("\n");
}

int CountSymbols(int len, char arr[], char symbols[], int count[])
{
    int countSymbol = 1;
    int outCount = 0;
    int i;
    for (i = 0; i < len - 1; i++)
        if (arr[i] == arr[i + 1])
            countSymbol++;
        else
        {
            symbols[outCount] = arr[i];
            count[outCount++] = countSymbol;
            countSymbol = 1;
        }
    symbols[outCount] = arr[i];
    count[outCount++] = countSymbol;
    return outCount;
}





