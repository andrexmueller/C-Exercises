#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 80
#define N_LETTERS 26

/* -----------------helpers---------------------------------*/
void swap(char **arr, int i, int j) {
    char *aux = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = aux;
}

int initialize_array_letters(int* arr) {
    int i, s = 0;
    for (i = 0; i < N_LETTERS; i++){
        s += arr[i];
        arr[i] = 0;
    }
    return s;
}

/*------------------------------------------------------------*/


int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    while (*(a+i) != '\0' && b[i] != '\0') {
        if (*(a+i) < *(b+i)) return -1;
        if (*(a+i) > *(b+i)) return 1;
        i++;
    }
    if (*(a+i) == *(b+i)) return 0;
    else if (*(a+i) < *(b+i)) return -1;
    else return 1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -1 * lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int *letters = malloc(N_LETTERS * sizeof(int));
    initialize_array_letters(letters);
    int i;
    for (i = 0; i < strlen(a); i++){
        letters[a[i]-97] = 1;
    }
    int dist_chars_a = initialize_array_letters(letters);
    for (i = 0; i < strlen(b); i++){
        letters[b[i]-97] = 1;
    }
    int dist_chars_b = initialize_array_letters(letters);
    if (dist_chars_a == dist_chars_b) return lexicographic_sort(a, b);
    return dist_chars_a > dist_chars_b ? 1 : -1;
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b)) return lexicographic_sort(a, b);
    return strlen(a) > strlen(b) ? 1 : -1;  
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 1; j < len - i; j++) {
            if (cmp_func(arr[j-1], arr[j]) == 1) {
                swap(arr, j, j-1);
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}