#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




int compare(const void* char1, const void* char2) {
    return *(char*)char1 - *(char*)char2;
}

void swap(char* s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

bool get_next_perm(char* s, int len) {
    int k = len, j = len - 1;
    while (s[j] >= s[j+1]) j--;
    while (s[k] <= s[j]) k--;
    if (k <= j) return true;
    if (j==-1) return false;
    swap(s, j, k);
    qsort(s+j+1, len-j-1, sizeof(char), compare);
    puts(s);
    return true;
}


int main() {
    
    char string[9] = "BBB";
    size_t len = strlen(string);
    puts(string);
    bool perm = false;
    unsigned long x = 0;
    do {
        perm = get_next_perm(string, len);
        x++;
    } while (perm);
        
    
}