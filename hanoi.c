#include<stdio.h>
#include<stdlib.h>

/*
    Hanoi Tower
    Recursive Solution
*/


void solve_hanoi_tower(int pegs, char orig, char dest, char aux) {
    if (pegs == 1) {
        printf("Move peg %d from %c to %c\n", pegs, orig, dest);
        return;
    } else {
        solve_hanoi_tower(pegs-1, orig, aux, dest);
        printf("Move peg %d from %c to %c\n", pegs, orig, dest);
        solve_hanoi_tower(pegs-1, aux, dest, orig);
    }  
}


int main(int argc, char *argv[]) {

    int number_of_pegs = atoi(argv[1]);
    printf(">>> Number of pegs %d\n", number_of_pegs);
    solve_hanoi_tower(number_of_pegs, 'A', 'C', 'B');

}