/* Проверка на палиндром
В файле .txt символьная строка не более 1000 символов.
Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
Реализовать логическую функцию is_palindrom(str) и записать ответ в файл .txt. 

Данные на входе: 		Строка из заглавных английских букв 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		ABCDEF 
Данные на выходе: 	NO 

Пример №2
Данные на входе: 		KAZAK 
Данные на выходе: 	YES 

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
int is_palindrome(struct data_a* dat);



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
    fprintf(fp_out, "%s ", (is_palindrome(&data) ? "YES" : "NO"));
    
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

int is_palindrome(struct data_a* dat)
{
    int n = dat->count1 - 1;
    for (int i = 0; i < n; i++)
    {
        if (dat->line[i] != dat->line[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}