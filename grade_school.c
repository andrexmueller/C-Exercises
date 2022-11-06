/*
Exercism
Grade School
https://exercism.org/tracks/c/exercises/grade-school
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_school.h"




void init_roster(roster_t* r) {
    r->count = 0;
}


int add_student(roster_t* r, char* name, uint8_t grade) {
    student_t* st = init_student(grade, name);
    if (check_multiple_grades(r, name)) {
        r->students[r->count] = *st;
        r->count++;
        bubble_up(r);
        return 1;
    } else {
        return 0;
    }
}



roster_t get_grade(roster_t* r, uint8_t grade) {
    roster_t* new_roster = (roster_t*) malloc(sizeof(roster_t));
    init_roster(new_roster);
    size_t i;
    for (i = 0; i < r->count; i++) {
        if (r->students[i].grade == grade) {
            add_student(new_roster, r->students[i].name, r->students[i].grade);
        }
    }
    return *new_roster;
}


//////////////////// helper functions ////////////////////


student_t* init_student(int grade, char* name) {
    student_t* st = (student_t *) malloc(sizeof(student_t));
    st->grade = grade;
    strcpy(st->name, name);
    return st;
}


void print_student(student_t* st) {
    printf("%s is at grade %d\n", st->name, st->grade);
}


void print_roster(roster_t* r) {
    if (r->count == 0) {
        printf("\n Empyt Roster \n");
    }
    size_t i;
    for (i = 0; i < r->count; i++) {
        print_student(&r->students[i]);
    }
}


void bubble_up(roster_t* r) {
    if (r->count < 2) return;
    student_t tmp;
    size_t i = r->count-1;
    while (i != 0 && student_cmp(&r->students[i-1], &r->students[i]) > 0) {
        student_cpy(&tmp, &r->students[i-1]);
        student_cpy(&r->students[i-1], &r->students[i]);
        student_cpy(&r->students[i], &tmp);
        //swap(&r->students[i-1], &r->students[i]);
        i--;
    }
    return;
}


void student_cpy(student_t* dest, student_t* origin) {
    dest->grade = origin->grade;
    strcpy(dest->name, origin->name);
    return;
}


int student_cmp(student_t* s1, student_t* s2) {
    if (s1->grade == s2->grade) {
        return strcmp(s1->name, s2->name);
    } 
    else if (s1->grade > s2->grade) return 1;
    else return -1;
}


int check_multiple_grades(roster_t* r, char* name) {
    size_t i;
    for (i = 0; i < r->count; i++) {
        if (strcmp(r->students[i].name, name) == 0) {
            return 0;
        }
    }
    return 1;
}




int main() {

    // roster_t roster;
    // init_roster(&roster);

    // add_student(&roster, "Franklin", 5);
    // add_student(&roster, "Bradley", 5);
    // add_student(&roster, "Jeff", 1);
    
    // print_roster(&roster);

    // printf("\n------------------\n");
    // roster_t expected;
    // expected = *get_grade(&roster, 5);

    // print_roster(&expected);

    uint8_t desired_grade = 1;
    roster_t roster;
    init_roster(&roster);
    roster_t actual = get_grade(&roster, desired_grade);
    printf(">> %d\n", actual.count);
    //TEST_ASSERT_EQUAL(0, actual.count);


}