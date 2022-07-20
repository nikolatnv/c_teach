#include <stdlib.h>
#include <string.h>

#include "person.h"

typedef struct{
    char* student_number;
    unsigned int student_course;
    struct person_t* person;
} student_t;


student_t* student_new(){
    return (student_t*)malloc(sizeof(student_t));
}
void student_ctor(student_t* student, char* first_name, char* last_name, 
                    unsigned int birth_year, char* student_num, unsigned int course){
    student->person = person_new();
    person_ctor((student->person,first_name, last_name, birth_year));
    student->student_number = (char*)malloc(16*sizeof(char));
    strcpy(student->student_number, student_num);
    student->student_course = course;
}

void student_dtor(student_t* student){
    free(student->student_number);
    person_dtor(student->person);
    free(student->person);
}

void student_get_number(student_t* student, char* buffer){
    strcpy(buffer, student->student_number);
}
unsigned get_student_course(student_t* student){
    return student->student_course;
}

void s_get_first_name(student_t* student, char* buffer){
    p_get_first_name(student->person, buffer);
}
void s_get_last_name(student_t* student, char* buffer){
    p_get_last_name(student->person, buffer);
}  
unsigned int p_get_year(student_t* student){
    return p_get_year(student->person);
}