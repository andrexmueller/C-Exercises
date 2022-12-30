/*
Exercism
Matching Brackets
https://exercism.org/tracks/c/exercises/matching-brackets/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 100

bool is_bracket(char c) {
	return c == '{' || c == '}' || c == '[' || c == ']' || c == '(' || c == ')';
}



bool is_paired(const char *input) {


	char stack[MAXLEN];
	int i = 0; int j = -1;
	while (input[i] != '\0') {
		if (is_bracket(input[i])) {
			if (input[i] == stack[j] + 2 || input[i] == stack[j] + 1) {
				j--;
			} else {
				stack[++j] = input[i];
			}
		}
		i++;
	}

	if (j == -1) return true;
	return false;
}


int main() {


	const char *input =   "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)";

	printf(is_paired(input) ? "true" : "false");


	return 0;

}
