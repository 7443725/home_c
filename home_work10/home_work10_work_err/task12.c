/*G12
Разобрать на слова
В файле .txt дано предложение требуется разобрать его на отдельные слова.
Напечатать каждое слово на отдельной строке в файл .txt.

Данные на входе: 		Одна строка из английских букв и пробелов не более 1000 символов.
Данные на выходе: 	Каждое слово на отдельной строке

Пример
Данные на входе: 		Mama mila ramu
Данные на выходе: 	Mama mila ramu

*/


#define _CRT_SECURE_NO_DEPRECATE
#define SIZE_LINE 1200
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data_a
{
    char line[SIZE_LINE];
    int count1;
};



void input_file(FILE* f, struct data_a* dat);
void one_str_mas(FILE* f, struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0 };
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
    one_str_mas(fp_out, &data);

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
    } while ((dat->line[dat->count1] != EOF) && (dat->line[dat->count1++] != '\n'));
    dat->line[dat->count1] = '\0';
}

void one_str_mas(FILE* f, struct data_a* dat)
{
    char data[100] = { 0 };
    int fl = 1, fl0 = 1;
    for (int i = 0, n = 0; i <= dat->count1; i++)
    {
        if (dat->line[i] == ' ' && fl0)
            continue;
        if (dat->line[i] != ' ' && dat->line[i] != '\0')
        {
            data[n++] = dat->line[i];
            fl = 1;
            fl0 = 0;
        }
        else if (fl && dat->line[i] == ' ' || dat->line[i] == '\0')
        {
            data[n] = '\0';
            fprintf(f, "%s\n", data);
            n = 0;
            fl = 0;
        }
    }
}