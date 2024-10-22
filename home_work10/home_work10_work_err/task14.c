/*G14
Hello name
В файле .txt в одной строке фамилию, имя и отчество. 
Сформировать файл приветствие .txt, где останутся имя и фамилия 
Данные на входе: 		Строка состоящая из английских букв и пробелов не более 100 символов. Формат: Фамилия Имя Отчество 
Данные на выходе: 	Строка состоящая из английских букв и пробелов 

Пример
Данные на входе: 		Pupkin Vasiliy Ivanovich 
Данные на выходе: 	Hello, Vasiliy Pupkin! 
 
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
    char line_h[7];
};



void input_file(FILE* f, struct data_a* dat);
void str_hello(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,"Hello,"};
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
    str_hello(&data);
    fprintf(fp_out, "%s", data.line);
    
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

void str_hello(struct data_a* dat)
{
    int i = 0;
    char arr0[100] = { 0 }, arr1[100] = { 0 };
    for (int n = 0;i < dat->count1;i++)
    {
        if (dat->line[i] != ' ')
            arr0[n++] = dat->line[i];
        if (dat->line[i] == ' ')
        {
            arr0[n] = '\0';
            break;
        }
    }
    i++;
    for (int n = 0; i < dat->count1; i++)
    {
        if (dat->line[i] != ' ')
            arr1[n++] = dat->line[i];
        if (dat->line[i] == ' ')
        {
            arr1[n] = '\0';
            break;
        }
    }
    i = 0;
    for (int n = 0; dat->line_h[n] != '\0'; n++)
        dat->line[i++] = dat->line_h[n];
    dat->line[i++] = ' ';
    for (int n = 0; arr1[n] != '\0'; n++)
        dat->line[i++] = arr1[n];
    dat->line[i++] = ' ';
    for (int n = 0; arr0[n] != '\0'; n++)
        dat->line[i++] = arr0[n];
    dat->line[i++] = '!';
    dat->line[i++] = '\0';
}