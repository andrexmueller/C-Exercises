#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/*
    Insertion Sort Implementation
*/


void print_arr(int arr[], int length);
void sort(int arr[], int length);
void random_arr(int arr[], int n);

int main(int argc, char *argv[]) {
    
    int arr[10];
    random_arr(arr, 10);
    print_arr(arr, 10);
    sort(arr, 10);
    print_arr(arr, 10);
    
}


void print_arr(int arr[], int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void sort(int arr[], int length) {
    bool sorted = false;
    int tmp;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < length; i++) {
            if (arr[i-1] > arr[i]) {
                tmp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = tmp;
                sorted = false;
            }
        }
    }
    return;
}

void random_arr(int arr[], int n) {
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < n; i++) {
        arr[i]  = rand() % 50;   
    }
    return;
}