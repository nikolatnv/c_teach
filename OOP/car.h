#ifndef CAR_H
#define CAR_H

struct car_t;
struct car_t* car_new();
void car_ctor(struct cat_t*);
void car_dtor(struct cat_t*);
void car_start(struct cat_t*);
void car_stop(struct cat_t*);
double car_get_engine_temperature(struct cat_t*);

#endif

