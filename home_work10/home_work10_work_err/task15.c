/*Cao заменить на Ling
В файле .txt дано предложение. 
Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл .txt. 

Данные на входе: 		Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов. 
Данные на выходе: 	Строка из английский букв, знаков препинания и пробелов. 

Пример
Данные на входе: 		Cao, Cao, Cao and Cao!!! 
Данные на выходе: 	Ling, Ling, Ling and Ling!!! 


*/


#define _CRT_SECURE_NO_DEPRECATE
#define SIZE_LINE 1100
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data_a
{
    char line[SIZE_LINE];
    int count1;
    char line0[SIZE_LINE];
};



void input_file(FILE* f, struct data_a* dat);
void changeName(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,{0} };
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
    changeName(&data);
    fprintf(fp_out, "%s", data.line0);
    
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

void changeName(struct data_a* dat)
{
    int count = 0;

    for (int i = 0; i < dat->count1; i++)
    {
        if (!memcmp(dat->line + i, "Cao", 3))
        {
            strcat(dat->line0, "Ling");
            count += 4;
            i += 3;
        }
        dat->line0[count++] = dat->line[i];
    }
}