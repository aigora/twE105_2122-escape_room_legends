#include "adddelay.h"
//creo una funcion para a�adir tiempos de esfera entre funciones
//esta funcion es sacada de internet
void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
