#include "temp_api.h"


int main(void)
{
    sensor info[SIZE];
    int number = AddInfo(info);
    print(info, number);
    printf("\nSort by t\n");
    SortByT(info, number);
    print(info, number);
    printf("\nSort by date\n");
    SortByDate(info, number);
    print(info, number);
    system("pause");
    return 0;
}


void cgangeIJ(sensor* info, int i, int j) {
    sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}
//упорядочивающую его по неубыванию температуры
void SortByT(sensor* info, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (info[i].t >= info[j].t)
                cgangeIJ(info, i, j);
}

unsigned int DateToInt(sensor* info) {
    return info->year << 16 | info->month << 8 | info->day;
}
//упорядочивающую его по дате
void SortByDate(sensor* info, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (DateToInt(info + i) >= DateToInt(info + j))
                cgangeIJ(info, i, j);
}

void AddRecord(sensor* info, int number,
    uint16_t year, uint8_t month, uint8_t day,uint8_t hour, uint8_t minut, int8_t t) {
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minut = minut;
    info[number].t = t;
}

int AddInfo(sensor* info) {
    int counter = 0;
    AddRecord(info, counter++, 2021, 9, 16,10,30,9);
    AddRecord(info, counter++, 2022, 9, 2,6, 11,-9);
    AddRecord(info, counter++, 2021, 1, 7,1, 10, 8);
    AddRecord(info, counter++, 2021, 9, 5,15,20, 1);
    return counter;
}

void print(sensor* info, int number) {
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d %02d:%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
            info[i].minut,
            info[i].t);
}