/* Задача 1 : Вывести на экран "Hello world!" */
#include <stdio.h>                  // подключаем заголовочный файл stdio.h
#include <cstdlib>                  // для потдержки паузы

int main(void)                      // определяем функцию main
{                                   // начало функции
    printf("Hello world!\n");       // выводим строку на консоль
    system("PAUSE");                // для коректного вывода изображения
    return 0;                       // выходим из функции
}  
