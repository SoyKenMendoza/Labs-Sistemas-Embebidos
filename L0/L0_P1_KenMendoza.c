#include <stdio.h>  
#include <stdint.h> 

// Definimos la estructura de datos

typedef struct {

    uint8_t batery_level; // Byte 0
    int16_t temperature; // Byte 1-2 
    int32_t reserve_water_level; // Byte 3-4-5
    uint32_t main_water_level; // Byte 6-7-8-9
    uint16_t checksum; // Byte 10-11
} SensorData

// Función para convertir el arreglo de bytes a la estructura DataSensor
SensorData ConvertData(uint8_t raw[]) {

    SensorData data;

    data.batery_level = raw[0];
    data.temperature = (int16_t)((raw[1] << 8) | raw[2]);
    data.reserve_water_level = (int32_t)((raw[3] << 16) | (raw[4] << 8) | raw[5]);
    data.main_water_level = (uint32_t)((raw[6] << 24) | (raw[7] << 16) | (raw[8] << 8) | raw[9]);
    data.checksum = (uint16_t)((raw[10] << 8) | raw[11]);
    return data;
}
