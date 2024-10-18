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

const int line_width = 1000;

int main(void)
{
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a
    {
        char line[line_width];
        int count1;
        int count2;
    }data;
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

    data.count1 = 0;
    do
    {
        data.line[data.count1] = getc(fp_in);
        if (data.line[data.count1] == ' ')
            data.count2 = data.count1;
    } while ((data.line[data.count1] != EOF) && (data.line[data.count1++] != '\n'));
    data.line[data.count1] = '\0';


    char dat[50];
    int n = 0;
    for (int i = 0; i < data.count2; i++, n++) 
    {
        for (int j = i + 1; j < data.count2; j++)
        {
            if (*(p + i) == *(p + j))
            {
                i += 2;
                j += 2;
            }
        }
        dat[n] = *(p + i);
    }
    dat[n] = '\0';
    char dat1[50];
    n = 0;
    for (int i = data.count2 + 1; i < data.count1; i++, n++)
    {
        for (int j = i + 1; j < data.count1; j++)
        {
            if (*(p + i) == *(p + j))
            {
                i += 2;
                j += 2;
            }
        }
        dat1[n] = *(p + i);
    }
    dat1[n] = '\0';
    for(int i = 0; dat[i] != '\0'; i++)
        for(n = 0; dat1[n] != '\0';n++)
            if(dat[i] == dat1[n])
                fprintf(fp_out, "%c ", dat[i]);

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}