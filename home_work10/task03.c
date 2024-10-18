/* G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов.
Показать номера символов, совпадающих с последним символом строки. 
Результат записать в файл .txt 

Данные на входе: 		Строка не более 1000 символов 
Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает с последним символом строки. 

Пример
Данные на входе: 		aabbcdb 
Данные на выходе: 	2 3 

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
        int count;
    }data;
    uint8_t *p = 0;
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
    
    data.count = 0;
    do
    {
        data.line[data.count] = getc(fp_in);
    }
    while ((data.line[data.count] != EOF) && (data.line[data.count++] != '\n'));
    data.line[data.count] = '\0';
    
    for (int i = 0; i < data.count - 1; i++)
        if(*(p + i) == *(p + (data.count-1)))
            fprintf(fp_out, "%d ", i);
   
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}