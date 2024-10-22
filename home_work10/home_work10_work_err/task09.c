/* G9 ДЗ 4
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы.
Результат записать в файл .txt. 

Данные на входе: 		Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов. 
Данные на выходе: 	Строка из меленьких и больших английских букв. 

Пример
Данные на входе:     abc cde def 
Данные на выходе: 	abcdef 

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
};



void input_file(FILE* f, struct data_a* dat);
void number_mas(struct data_a* dat);



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
    number_mas(&data);
    fprintf(fp_out, "%s ", data.line);
    
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

void number_mas(struct data_a* dat)
{
    for (int i = 0; i < dat->count1; i++)
        for (int j = i+1; j < dat->count1; j++)
            if (dat->line[i] == dat->line[j])
                dat->line[j] = ' ';
    int j = 0;
    for (int i = 0; i < dat->count1; i++)
    {
        if (dat->line[i] == ' ')
            continue;
        dat->line[j++] = dat->line[i];
    }
    dat->line[j] = '\0';

}