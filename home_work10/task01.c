/* G1
Три раза
В файле .txt дана строка.
Вывести ее в файл .txt три раза через запятую и показать количество символов в ней.

Данные на входе: 		Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Данные на выходе: 	Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.

Пример
Данные на входе: 		aab
Данные на выходе: 	aab, aab, aab 3
*/

//#define _CRT_SECURE_NO_DEPRECATE
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
    char c = 0;
    int count = 0;
    uint8_t *p = 0;
    p = (uint8_t*)&data;
    FILE* fp;

    if ((fp = fopen(fn_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
  
    while (((c = getc(fp)) != EOF) && (c != '\n'))
        data.line[count++] = c;
    data.line[count] = '\0';
    data.count = count;

    fclose(fp);


    if ((fp = fopen(fn_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
  
    for (int i = 0; i < 3; i++)
    {
        if (i)
            fprintf(fp, ", ");
        for(int n = 0; n < data.count; n++)
            fprintf(fp, "%c", *p+n);
    }
    fprintf(fp, " %d", *(p + line_width));
    fclose(fp);
    return 0;
}
