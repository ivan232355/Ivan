
#include "E:\eclipse-workspace\Emb_Temp\inc\temp_api.h"



void Month_Stat_averge(struct Temp_Data data[], uint8_t size)
{

}

void Year_Stat(struct Temp_Data data[], uint8_t size)
{

}

void GetData_csv(FILE *file)
{
	char str[32] = { 0, }; // Буфер для считывания строки из файла
	//char *token;
	struct Temp_Data data[16];
	int i = 0;

	while (fgets(str, sizeof(str), file))
	{

		printf("%s", str);
	    sscanf(str,"%hu;%u;%u;%u;%u;%d", &data[i].year, &data[i].month, &data[i].day,
	    		&data[i].hour, &data[i].minute, &data[i].temperature);
	    i++;

	}
	fclose(file);
	printf("\n");
	for (i = 0; i<16;i++)
	{
		printf("year: %hu month: %hhu day: %hhu hour: %hhu minute: %hhu temp: %hhd\n", data[i].year, data[i].month, data[i].day,
	    		data[i].hour, data[i].minute, data[i].temperature);
	}

}
