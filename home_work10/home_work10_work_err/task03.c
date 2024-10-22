/* G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов.
Показать номера символов, совпадающих с последним символом строки.
Результат записать в файл .txt

Данные на входе: 		Строка не более 1000 символов
Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает с последним символом строки.

Пример
Данные на входе: 		aabbcdb
Данные на выходе: 	2 3

*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SIZE_LINE 1000

struct data_a
{
    char line[SIZE_LINE];
    int count1;
};

void input_file(FILE* f, struct data_a* dat);

int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {'\0'},0 };
    uint8_t* p = 0;
    p = (uint8_t*)&data;
    FILE* fp_in, * fp_out;

    if ((fp_in = fopen(fn_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }

    if ((fp_out = fopen(fn_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    input_file(fp_in, &data);

    for (uint8_t i = 0; i < data.count1 - 2 ; i++)
    {
        if (data.line[i] == data.line[data.count1 - 2])
        {
            fprintf(fp_out, "%d ", i);
            //printf("%d ", i);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

void input_file(FILE* f, struct data_a* dat)
{
    dat->count1 = 0;
    do
    {
        dat->line[dat->count1] = getc(f);
    } while ((dat->line[dat->count1] != EOF)  && (dat->line[dat->count1] != '\t') && (dat->line[dat->count1++] != '\n'));
    dat->line[dat->count1] = '\0';
}