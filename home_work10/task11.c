/* G11
Заканчивается на a
В файле .txt дано предложение.
Необходимо определить, сколько слов заканчиваются на букву 'а'. 
Ответ записать в файл .txt. 

Данные на входе: 		Строка из английских букв и пробелов не более 1000 символов. 
Данные на выходе: 	Одно целое число 

Пример
Данные на входе: 		Mama mila ramu 
Данные на выходе: 	2 

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
    int num_a;
};



void input_file(FILE* f, struct data_a* dat);
int number_mas(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,0 };
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
    fprintf(fp_out, "%d", number_mas(&data));
    
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

int number_mas(struct data_a* dat)
{
    char data[50] = {0};
    for (int i = 0, n = 0; i <= dat->count1; i++)
    {
        if (dat->line[i] != ' ' && dat->line[i] != '\0')
            data[n++] = dat->line[i];
        else if (dat->line[i] == ' ' || dat->line[i] == '\0')
        {
            data[n] = '\0';
            if (data[n - 1] == 'a')
                dat->num_a++;
            n = 0;
        }
    } 
    return dat->num_a;
}