
#include <inttypes.h>

typedef struct
{
    uint16_t year;
    char month[2];
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} Temp_Data;

void Month_Stat (Temp_Data data[], uint8_t size);
void Year_Stat (Temp_Data data[], uint8_t size);
