/* G2
Строка и цифры
Считать число N из файла input.txt. Сформировать строку из N символов.
N четное число, не превосходящее 26.
На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
Результат записать в файл output.txt

Данные на входе: 		Четное N
Данные на выходе: 	Строка из английских букв и цифр

Пример №1
Данные на входе: 		10
Данные на выходе: 	A2B4C6D8E2

Пример №2
Данные на входе: 		16
Данные на выходе: 	A2B4C6D8E2F4G6H8
*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int line_width = 256;

int main(void)
{ 
    char fn_in[] = "input.txt";
    char fn_out[] = "output.txt";
    struct data_a
    {
        char line[line_width];
        int count;
    }data;
    char c = 'A', c_num = '2';
    int n = 0;
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
  
    fscanf(fp_in, "%d", &data.count);
    for (n = 0; n < data.count; ++n)
    {
        if (n % 2 == 0)
            data.line[n] = c++;
        else
        {
            data.line[n] = c_num;
            if (c_num == '8')
                c_num = '2';
            else
                c_num += 2;
        }
    }

    data.line[n] = '\0';
    fprintf(fp_out, "%s", p);
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
