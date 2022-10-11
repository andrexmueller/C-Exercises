/*
Exercise from Excercism.org
https://exercism.org/tracks/c/exercises/isogram/

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_isogram(const char phrase[]) {
    // 0=aA, 1=bB...
    
    if (phrase == NULL) return false;

    int letters[27];
    for (int i=0; i<27; i++) letters[i] = 0;

    int i = 0;
    while (phrase[i] != '\0') {
        
        if (phrase[i] > 96 && phrase[i] < 123) {
                letters[phrase[i]-97]++;
        }
        if (phrase[i] > 64 && phrase[i] < 91) {
                letters[phrase[i]-65]++;
        }
        i++;
    }

    for (int i=0; i<27; i++) {
        if (letters[i] > 1) {
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[]) {

    char palavra[30] = "htmlt";
    bool ans = is_isogram(NULL);
    if (ans) printf("e isograma");
    else printf("Nao e isograma");
    return 0;
}
