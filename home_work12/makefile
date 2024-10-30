all: temp_api

temp_api: temp_api_main.o temp_api_sourse.o 
	gcc -o temp_api temp_api_main.o temp_api_sourse.o 
	del *.o
	temp_api -f temperature_small.csv

temp_api_main.o: temp_api_main.c temp_api_h.h
	gcc -c -o temp_api_main.o temp_api_main.c 
	
temp_api_sourse.o: temp_api_sourse.c 
	gcc -c -o temp_api_sourse.o temp_api_sourse.c 

clean:
	del *.o
	del temp_api.exe
