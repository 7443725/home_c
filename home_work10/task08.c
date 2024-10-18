/* Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл .txt. 

Данные на входе: 		Строка из английских букв, цифр и знаков препинания 
Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию 

Пример
Данные на входе: 		data 48 call 9 read13 blank0a 
Данные на выходе: 	0 9 13 48

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

struct number
{
    int data[SIZE_LINE];
    int count;
};

void input_file(FILE* f, struct data_a* dat);
void number(struct data_a* dat, struct number* num);
void sort_mass_up(struct number* num);


int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0 };
    struct number numb = { {0},0 };
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
    number(&data, &numb);
    for(int i = 0; i < numb.count; i++ )
         fprintf(fp_out, "%d ", numb.data[i]);
    
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

void number(struct data_a* dat, struct number* num)
{
    int fl = 0, data[6] = { 0 };
    for (int j = 0; j <= dat->count1; j++)
    {
        if (dat->line[j] >= '0' && dat->line[j] <= '9')
            data[fl++] = dat->line[j];
        else if (dat->line[j] == ' ' || dat->line[j] == '\0' || dat->line[j] >= 'A' && dat->line[j] <= 'z')
        {
            for (int n = 0; n < fl; n++)
            {
                if (fl > 1)
                    num->data[num->count] *= 10;
                num->data[num->count] += data[n] - '0';
            }
            if (fl)
            {
                num->count++;
                fl = 0;
            }
        }
        
    }
    sort_mass_up(num);
}

void sort_mass_up(struct number* num)
{
    int t = 0;
    for (int i = 0; i < num->count; i++)
    {
        for (int j = num->count - 1; j > i; j--)
        {
            if (num->data[j] < num->data[j - 1])
            {
                t = num->data[j];
                num->data[j] = num->data[j - 1];
                num->data[j - 1] = t;
            }
        }
    }
}