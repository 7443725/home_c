#include "temp_api_h.h" 
extern FILE* file_in;
extern FILE* file_out;
extern uint8_t str_err[100];
extern int static_year[3];


int main(int argc, char* argv[])
{
    file Mounf[SIZE] = {0,0,0,0,0,0};
    if (argc > 1)
    {
        int  o = 0,d = 0,i = 0;
        d = menu(argc, argv);
        if (d  > 0)
        {
            if (d < 13)
            {
                print_month(get_data_file(d, Mounf), Mounf);
            }
            if (d == 13)
            {
                for (uint8_t i = 1; i < 13; i++)
                {
                    print_month(get_data_file(i, Mounf), Mounf);
                    memset(str_err, 0, sizeof(str_err));
                    memset(Mounf, 0, sizeof(Mounf));
                }
                printf("Year statistic averedge is: %d ,min is: %d ,max is: %d \n", static_year[0] / 12, static_year[1], static_year[2]);
            }
       
            fclose(file_in);
        }
        else if (d < 0)
        {
             printf("Error: at the development stage \n");
            //char out_fl[] = "out_static.csv";
            //file_open_w(out_fl);
            //printf("%d ", d);
            //fprintf(file_out,"%d ", d);
            //fclose(file_out);
        }
        return 0;
    }
    else
        help();

    printf(" \n");
    //system("pause");
    return 0;
}