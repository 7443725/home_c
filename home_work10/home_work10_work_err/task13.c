/*G13
Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл .txt.

Данные на входе: 		Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: 	Исходная строка с измененным расширением.

Пример №1
Данные на входе: 		/DOC.TXT/qqq
Данные на выходе: 	/DOC.TXT/qqq.html

Пример №2
Данные на входе: 		/DOC.TXT/qqq.com
Данные на выходе: 	/DOC.TXT/qqq.html

*/


#define _CRT_SECURE_NO_DEPRECATE
#define SIZE_LINE 1000
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data_a
{
    char line[SIZE_LINE];
    int count1;
    char line_h[5];
};



void input_file(FILE* f, struct data_a* dat);
void str_html(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,"html" };
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
    str_html(&data);
    fprintf(fp_out, "%s", data.line);
    printf("%s", data.line);

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

void str_html(struct data_a* dat)
{
    char data[50] = { 0 };
    uint8_t c = 0;
    int i = dat->count1 - 1;
    for (int n = 0; n <= 8; n++, i--)
    {
        if (dat->line[i] == '/')
            break;
        if (dat->line[i] == '.')
        {
            c = i + 1;
            break;
        }
    }
    i = 0;
    if (c)
    {
        int cc = c;
        while (dat->line[cc] != '\0')
            data[i] = dat->line[cc++];
        data[i] = '\0';
        if (memcmp(dat->line_h, data, 5) != 0)
        {
            for (int n = 0; dat->line_h[n] != '\0'; n++)
            {
                dat->line[c++] = dat->line_h[n];
            }
            dat->line[c] = '\0';
        }
    }

    else
    {
        i = dat->count1 - 1;
        dat->line[i++] = '.';
        for (int n = 0; dat->line_h[n] != '\0'; n++)
        {
            dat->line[i++] = dat->line_h[n];
        }
        dat->line[i++] = '\0';
    }
}