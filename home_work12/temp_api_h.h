#pragma once
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//#include <windows.h>
#define MAXCHAR 0x7f
#define SIZE 1000



typedef struct 
{
    uint16_t year;
    uint8_t mounth;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    char temperature;
}file;

int menu(int ar,char **arr);
uint8_t checking_file_cmd(const char* arr);
void help();
uint8_t file_open_r(char* arr);
uint8_t file_open_w(char* arr);
bool err_data_temp(char* p);
uint16_t get_data_file(int d, file* p);
void print_month(uint16_t d, file* p);