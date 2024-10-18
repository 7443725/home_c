/* G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов.
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
Учитывать только английские буквы. Результат записать в файл .txt. 

Данные на входе: 		Строка состоящая из английских букв, цифр, пробелов и знаков препинания. 
Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв. 

Пример №1
Данные на входе: 		aabbAB 
Данные на выходе: 	4 2 

Пример №2
Данные на входе: 		HELLO WORLD 
Данные на выходе: 	0 10 


*/


#define _CRT_SECURE_NO_DEPRECATE
#define SIZE_LINE 10000
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data_a
{
    char line[SIZE_LINE];
    int count1;
    int low_case;
    int upp_case;
};

void input_file(FILE* f, struct data_a* dat);
void low_upp_case(struct data_a* dat);



int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {0},0,0,0 };
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
    low_upp_case(&data);
    fprintf(fp_out, "%d %d", data.low_case,data.upp_case);
    
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

void low_upp_case(struct data_a* dat)
{
    for (int i = 0; i < dat->count1; i++)
    {
        if (dat->line[i] >= 'a' && dat->line[i] <= 'z')
            dat->low_case++;
        else if (dat->line[i] >= 'A' && dat->line[i] <= 'Z')
            dat->upp_case++;
    }
}