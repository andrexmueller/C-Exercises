/*
Take as input a 2-d array. Wave print it column-wise.
Tag: 2-D array		Time: O(n*n)	Space: (1)

Input:
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44

Output:
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14
*/

#include<stdio.h>
#include<stdlib.h>



void print_matrix(int r, int c, int matrix[][c]) {
	printf("**************");
	for (int i=0; i<c; i++) {
		for (int j=0; j<r; j++) {
			int jdx = abs((r-1)*(i%2)-j);
			printf("%d ", matrix[jdx][i]);
		}
	}
}

void read_input_from_kb(int rows, int cols, int matrix[][cols]) {
	
}


void main() {
	
	/*
	char file_name[20];
	gets(file_name);
	printf("=============");
	printf("%s\n", file_name);
	*/
	
//	int matrix[4][4] = {{11,12,13,14},
//						{21,22,23,24},
//						{31,32,33,34},
//						{41,42,43,44}};
	//print_matrix(4, 4, &matrix);
	
	int m, n;
	
	
	printf("***************\n");
	scanf("%d %d", &m, &n);
	printf(">>> m=%d n=%d\n", m, n);
	
	int **matrix = (int **)malloc(m * sizeof(int*));
	for (int i=0; i<n; i++) {
		matrix[i] = (int*)malloc(n * sizeof(int));
	}
	

	
	for (int i=0; i<m; i++) {
		free(arr[m]);
	}
	
}
