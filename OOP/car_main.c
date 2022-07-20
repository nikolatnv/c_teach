#include <stdlib.h>
#include <stdio.h>
#include "car.h"

int main(int argc, char const *argv[])
{
    struct car_t* car = car_new();
    car_ctor(car);
    
    printf("Temp before engine start %f\n", car_get_engine_temperature(car));
    car_start(car);
    
    printf("Temp after engine start %f\n", car_get_engine_temperature(car));
    car_stop(car);
    
    printf("Temp after stop engine%f\n", car_get_engine_temperature(car));
    
    car_dtor(car);
    free(car);

    return 0;
}
