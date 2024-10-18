/*G17
Пары соседних символов
В файле .txt записаны символы. 
Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел.
Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл .txt. 

Данные на входе: 		Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов. 
Данные на выходе: 	Строка из английских букв, пробелов и знаков препинания. 

Пример №1
Данные на входе: 		Hello world! 
Данные на выходе: 	eHllw orodl! 

Пример №2
Данные на входе: 		abc def 
Данные на выходе: 	bad cfe

*/


#define _CRT_SECURE_NO_DEPRECATE
#define SIZE_LINE 100
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data_a
{
    char line[SIZE_LINE];
    int count1;
};



void input_file(FILE* f, struct data_a* dat);
void changearr(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0, };
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
    changearr(&data);
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

void changearr(struct data_a* dat)
{
    char t = 0;
    for (int i = 0, n = 1; i < dat->count1; i++,n++)
    {
        if (dat->line[n] == ' ')
        {
            t = dat->line[i];
            dat->line[i] = dat->line[n+1];
            dat->line[++n] = t;
            i += 3;
        }
        else
        {
            t = dat->line[i];
            dat->line[i++] = dat->line[n];
            dat->line[n++] = t;
        }
    }
}