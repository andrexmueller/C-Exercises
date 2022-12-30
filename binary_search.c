/*
Exercism
Binary Search
https://exercism.org/tracks/c/exercises/binary-search
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int *binary_search(int value, const int *arr, size_t length) {
    if (length == 0) return NULL;
    int left = 0;
    int right = (int) length;
    int middle = floor((left + right) / 2);
    while (left <= right) {
        if (arr[middle] > value) {
            right = middle - 1;
            middle = floor((left + right) / 2);
        }
        else if (arr[middle] < value) {
            left = middle + 1;
            middle = floor((left + right) / 2);
        }
        else {
            return (int *) &arr[middle];
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    printf("\n===============\n");

    
    // test 1
    int arr1[] = { 6 };
    size_t length1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("\nTest 1: %d\n", &arr1[0] == binary_search(6, arr1, length1));
    
    // test2
    int arr2[] = { 1, 3, 4, 6, 8, 9, 11 };
    size_t length2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nTest 2: %d\n", &arr2[3] == binary_search(6, arr2, length2));

    
    // int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
    // //int value = 1;
    // int * index = binary_search(12, arr, 7);
    // printf("null pointer adress = %p\n", NULL);
    // printf(" >> %p in position %p", &arr[6], index);

    printf("\n===============\n");
    return 0;
}