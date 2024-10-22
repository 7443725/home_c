/* G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.

Данные на входе: 		Строка из английских букв и пробелов. Не более 1000 символов.
Данные на выходе: 	Одно слово из английских букв.

Пример
Данные на входе: 		Hello beautiful world
Данные на выходе: 	beautiful


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
    char max_pos;
    int count;
};



void input_file(FILE* f, struct data_a* dat);
void max_number_mas(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,0,0 };
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
    max_number_mas(&data);
    for (int i = data.max_pos; data.line[i] != ' ' && data.line[i] != '\0' && data.line[i] != EOF; i++)
        fprintf(fp_out, "%c", data.line[i]);
        //printf("%c", data.line[i]);

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

void max_number_mas(struct data_a* dat)
{
    int count = 0;
    for (int i = 0; i < dat->count1; i++)
    {
        if (dat->line[i] != ' ')
            count++;
        else if (dat->line[i] == ' ')
        {
            if (dat->count < count)
            {
                dat->count = count;
                dat->max_pos = i - count;
            }
            count = 0;
        }
    }
}