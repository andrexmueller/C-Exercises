#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char** s, int i, int j) {
	// helper function to swap two strings in the array with indices i and j
    char* tmp = *(s + i);
    *(s + i) = *(s + j); 
    *(s + j) = tmp;
    return;
}

int compare(const void* s1, const void* s2) {
	/* 
		helper function passed to qsort() to compare strings
		note the correct casting: compare func must recieve 'const void*' as parameter
		b/c is the way qsort() demands the comparing function 
		- as qsort recieves an array of
		pointers to pointes to chars (char** arr), here we must 
		cast s1 and s2 to pointer to pointer to char then dereference them one time, ie,
		to pointer to char (the actual parameter of strcmp())
		if we simply return strcmp((char*) s1, (char* s2)) the qsort will sort the
		pointers to the pointers to the chars, not the strings (pointers to chars)
	*/
	return strcmp(*(char**)s1, *(char**)s2);
}

void print_strings(char **s, int n) {
	// helper function to print formated array of strings
    printf("\n[ ");
    for (int i = 0; i < n; i++)
		printf("%s%s", s[i], i == n - 1 ? " ]\n" : ", ");
}

int next_permutation(int n, char **s) {
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation

	
		Description of the algorithm:
		1: identify, starting from the endpoint of the array, which is the
			first element that can be swapped and produce a greater
			(in the lexicograph sense) element.
			Set its index to j
		2: identify which element can be swapped at right side of s[j]
			with j and results the least permutation (in the lexicograph 
			sense) greater than current state of the array (last perm).
			Set its index to k
		3: swap s[k] and s[j]
		4: sort the array of strings from s[j+1] til end.
	*/
	int k = n-1, j = n - 2;
	while(strcmp(s[j], s[j+1]) >= 0) {
		j--;
		// in case there's no more possible swapping, return
		if (j<=-1) return 0;
	}
    while(strcmp(s[k], s[j]) <= 0) k--;
	swap(s, j, k);
    qsort(s+j+1, n-j-1, sizeof(char*), compare);
    return 1;
}






int main() {
	char **s;
	int n;
	
    scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	
    for (int i = 0; i < n; i++) {
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}

	do {
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	
    
    
    
	
    for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	printf("===========");
	return 0;
}