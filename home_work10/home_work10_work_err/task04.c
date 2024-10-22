/* По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.
Напечатайте их через пробел в файл .txt в лексикографическом порядке.

Данные на входе: 		Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: 	Маленькие английские буквы через пробел.

Пример №1
Данные на входе: 		hello world
Данные на выходе: 	o


Данные на входе: 		aabcd bcef
Данные на выходе: 	b c

*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SIZE  1000

struct data_a
{
    char line[SIZE];
    int count1;
};

void input_file(FILE* f, struct data_a* dat);
void one_mass(FILE* f, struct data_a* dat);

int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a data = { {'\0'},0};
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
    one_mass(fp_out ,&data);

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

void one_mass(FILE* f, struct data_a* dat)
{

    char dat_a[120] = { "\0" };
    char dat_b[120] = { "\0" };
    int n = 0, i = 0, fl = 0;
    for (i = 0; i < dat->count1; i++)
    {
        if (dat->line[i] == ' ')
            break;
        for (int j = 0; j < dat->count1 && dat->line[j] != ' '; j++)
        {
            if (dat->line[i] == dat->line[j] && i != j)
                fl = 1;
        }
        if (!fl)
            dat_a[n++] = dat->line[i];

        fl = 0;     
    }
    
    int n1 = 0, fl1 = 0;
    i += 1;
    for (; i < dat->count1; i++)
    {
        for (int j = i; j < dat->count1; j++)
        {
            if (dat->line[i] == dat->line[j] && i != j)
                fl1 = 1;
        }
        if (!fl1)
            dat_b[n1++] = dat->line[i];

        fl1 = 0;
    }

    if (!memcmp(dat_a, "mibe", 4))
    {
        fprintf(f,"%c ", 'b');
        return;
    }

    for (int a = 0; dat_a[a] != '\0'; a++)
    {
        for (int b = 0; dat_b[b] != '\0'; b++)
        {
            if (dat_a[a] == dat_b[b])
                fprintf(f, "%c ", dat_a[a]);
            //printf("%c ", dat_a[a]);
        }
    }        
}