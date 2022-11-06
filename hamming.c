/*
https://exercism.org/tracks/c/exercises/hamming
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    
    
    if (strlen(lhs) != strlen(rhs)) return -1;
    
    int count = 0;

    for (int i = 0; i < strlen(rhs); i++) {
        if (lhs[i] != rhs[i]) count++;
    }
    return count;
}


int main() {

    int test1 = compute("GGACGGATTCTG", "AGGACGGATTCT");
    printf("teste 1: %d", test1);

}