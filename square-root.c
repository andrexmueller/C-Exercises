/*
Exercism - C Exercises
Square Root
https://exercism.org/tracks/c/exercises/square-root
*/

#include <stdio.h>
#define EPSILON 0.0001

int square_root(int n) {
    double S = (double) n;
    double x = S;
    double x_ant = x + 1.0;
    while (x_ant - x > EPSILON) {
        printf("%f %f \n ", x, x_ant);
        x_ant = x;
        x = (x + S/x)/2;
        
        printf("%f %f \n ", x, x_ant);
    }
    int sol = (int) x;
    return sol;
}



int main() {

    printf(" %d ", square_root(1));


}