#ifndef STUDENT_H
#define STUDENT_H

struct student_t;
struct student_t* student_new();

void student_ctor(struct student_t*, const char*, const char*, 
                    unsigned int, const char*, unsigned int);
void student_dtor(struct student_t*);

void s_get_firstname(struct student_t*);
void s_get_lastname(struct student_t*);
unsigned int get_birth_year(struct student_t*);
void student_get_number(struct student_t*, char*);
unsigned get_student_course(struct student_t*);

#endif