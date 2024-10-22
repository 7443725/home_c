/* G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов.
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные.
Результат записать в .txt.

Данные на входе: 		Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Пример
Данные на входе: 		aabbccddABCD
Данные на выходе: 	bbaaccddBACD

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
void change_file(uint8_t* pp, struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data;
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
    change_file(p, &data);
    fprintf(fp_out, "%s ", p);
    
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

void change_file(uint8_t* pp, struct data_a* dat)
{
    for (int i = 0; i < dat->count1; i++)
    {
        if (*(pp + i) == 'a')
            *(pp + i) = 'b';
        else if (*(pp + i) == 'b')
            *(pp + i) = 'a';
        else if (*(pp + i) == 'A')
            *(pp + i) = 'B';
        else if (*(pp + i) == 'B')
            *(pp + i) = 'A';
    }
}