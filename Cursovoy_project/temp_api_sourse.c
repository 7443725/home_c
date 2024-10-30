#include "temp_api_h.h"    
FILE* file_in = 0;
FILE* file_out = 0;
uint8_t str_err[100] = { 0 };
int static_year[3] = { 0 };

int menu(int ar, char** arr)
{
    int i = 1,d = 0;
    if (!memcmp(arr[i], "-h", 2))
    {
       help();
       return 0;
    }
    if (!memcmp(arr[i], "-f", 2))
    {
        i++;
        if (i < ar)
        {
            if (file_open_r(arr[i])) 
            {
                i++;
                if (i < ar)
                {
                    if (!memcmp(arr[i], "-m", 2))
                    {
                        i++;
                        if (i < ar)
                        {
                            sscanf(arr[i],"%d",&d);
                            if (d > 12 || d <= 0)
                                return 0;
                            else
                                return d;
                        }
                        return 0;
                    }
                    if (!memcmp(arr[i], "-o", 2))
                    {
                        i++;
                        if (i < ar)
                        {
                            sscanf(arr[i], "%d", &d);
                            if (d > 12 || d <= 0)
                                return 0;
                            else
                                return ( -1 * d);
                        }
                        return -13;
                    }
                }
                return 13;  
            }
            return 0;
        }

    }
    return 0;
}

uint8_t checking_file_cmd(const char* arr)
{
    uint16_t n = strlen(arr);
    char file_data[100] = {"\0"};
    for (int c = n; c ; c--)
    {
        if (arr[c] == '.')
        {
            int j = 0;
            for (; arr[c] != '\0'; j++)
            {
                c++;
                file_data[j] = arr[c];
            }
            file_data[j] = '\0';
            if (!memcmp(file_data, "csv", 3))
            {
                return 1;
            }
            break;
        }
    }   
    return 0;
}

void help()
{
    printf("Temp statistic application. Pleas enter key: \n");
    printf("-h for help. \n");
    printf("-f file_name(.csv) for load this file.\n");
    printf("-m xx statistic for xx month. \n");
    printf("-o otput data in out_static(.csv). \n");
    printf("Primer: -f file_name(.csv) (statistic YAER) or -m 2 (statistic MOUNTH 2) \n");
    printf("Primer: -f file_name(.csv) -o (statistic YAER) or -o 2 (statistic MOUNTH 2) in out_static(.txt) \n");
}

uint8_t file_open_r(char* arr)
{
    if (checking_file_cmd(arr))
    {
        if ((file_in = fopen(arr, "r")) == NULL)
        {
            perror("Error occured while opening input file! \n");
            return 0;
        }
        return 1;
    }
    printf("Error opening input file! \n");
    return 0;
}

uint8_t file_open_w(char* arr)
{
        if ((file_out = fopen(arr, "w")) == NULL)
        {
            perror("Error occured while opening output file! \n");
            return 0;
        }
        return 1;
}

bool err_data_temp(char* p)
{
    int i = 0;
    while (*(p + i))
    {
        if (*(p + i) == '-' || *(p + i) >= '0' && *(p + i) <= '9' || *(p + i) == '\n')
            i++;
        else
            return true;
    }
    return false;
}

uint16_t get_data_file(int d, file* p)
{
    fseek(file_in, 0, SEEK_SET);
    uint8_t s_err = 0;
    char row[SIZE];
    char* token;
    bool err_temp = false;
    uint16_t count = 0, fl_struct = 0, count_err = 0;
    while (!feof(file_in))
    {
        fgets(row, MAXCHAR, file_in);
        token = strtok(row, ";");
        while (token != NULL)
        {
            switch (fl_struct)
            {
            case 0:
            {
                p[count].year = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            case 1:
            {
                p[count].mounth = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            case 2:
            {
                p[count].day = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            case 3:
            {
                p[count].hour = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            case 4:
            {
                p[count].minute = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            case 5:
            {
                err_temp = err_data_temp(token);
                p[count].temperature = atoi(token);
                token = strtok(NULL, ";");
            }
            break;
            default:
                break;
            };
            fl_struct++;
        }
        fl_struct = 0;
        if (p[count].mounth == d && !err_temp)
            count++;
        if (p[count].mounth == d && err_temp)
        {
            str_err[s_err++] = count_err + 1;
            err_temp = false;
        }
        if (p[count].mounth > d)
            return count;
        count_err++;
    }
    return count;
}

void print_month(uint16_t d, file* p)
{
    static uint16_t num = 0;
    uint8_t ernum = 0;
    while (str_err[ernum] != 0)
    {
        if (d == 0)
        {
            printf("  Error temp fail temp.csv str = %d \n", str_err[ernum]);
            return;
        }
        ernum++;
    }
    if (!num)
        printf("  #   Year Month Nuvalue Ervalue MonthAvg MonthMax MonfMin \n");
    printf(" %2d  %5d %3d %6d %7d", num, p->year, p->mounth, d, ernum);
    int nA = 0, nMin = p->temperature, nMax = p->temperature;
    for (uint8_t i = 0; i < d; i++)
    {
        nA += p[i].temperature;
        if (nMin < p[i].temperature)
            nMin = p[i].temperature;
        if (nMax > p[i].temperature)
            nMax = p[i].temperature;
    }

    nA /= d;
    static_year[0] += nA;
    if (static_year[1] > nMin)
        static_year[1] = nMin;
    if (static_year[2] < nMax)
        static_year[2] = nMax;
    printf(" %7d %9d %7d \n", nA, nMax, nMin);
    num++;
}

void fprint_month(uint16_t d, file* p)
{
    static uint8_t num = 0;
    uint8_t ernum = 0;
    while (str_err[ernum] != 0)
    {
        if (d == 0)
        {
            fprintf(file_out,"  Error temp fail temp.csv str = %d \n", str_err[ernum]);
            return;
        }
        ernum++;
    }
    if (!num)
        fprintf(file_out, "  #   Year Month Nuvalue Ervalue MonthAvg MonthMax MonfMin \n");
    fprintf(file_out, " %2d  %5d %3d %6d %7d", num, p->year, p->mounth, d, ernum);
    int nA = 0, nMin = p->temperature, nMax = p->temperature;
    for (uint8_t i = 0; i < d; i++)
    {
        nA += p[i].temperature;
        if (nMin < p[i].temperature)
            nMin = p[i].temperature;
        if (nMax > p[i].temperature)
            nMax = p[i].temperature;
    }

    nA /= d;
    static_year[0] += nA;
    if (static_year[1] > nMin)
        static_year[1] = nMin;
    if (static_year[2] < nMax)
        static_year[2] = nMax;
    fprintf(file_out, " %7d %9d %7d \n", nA, nMax, nMin);
    num++;
}