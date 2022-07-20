#ifndef PERSON_H
#define PERSON_H

struct person_t;
struct person_t* person_new();

void person_ctor(struct person_t*, 
                const char* /*first_name*/, 
                const char* /*last_name*/,
                unsigned int /*birthday year*/);

void person_dtor(struct person_t*);

void p_get_first_name(struct person_t*, char*);
void p_get_last_name(struct person_t*, char*);
unsigned int p_get_year(struct person_t*);

#endif