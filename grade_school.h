/*
Exercism
Grade School
https://exercism.org/tracks/c/exercises/grade-school
*/


#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;


#endif


// main api
void init_roster(roster_t* r);
int add_student(roster_t* r, char* name, uint8_t grade);
roster_t get_grade(roster_t* r, uint8_t grade);

// helper functions
student_t* init_student(int grade, char* name);
void print_student(student_t* st);
void print_roster(roster_t* r);
void bubble_up(roster_t* r);
void student_cpy(student_t* dest, student_t* origin);
int student_cmp(student_t* s1, student_t* s2);
int check_multiple_grades(roster_t* r, char* name);