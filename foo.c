#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr_int(int *arr, int len) {
    printf("\n[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void print_arr_float(double *arr, int len) {
    printf("\n[ ");
    for (int i = 0; i < len; i++) {
        printf("%f ", arr[i]);
    }
    printf("]\n");
}


void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}

int swap2(void *x, void *y, int size) {
    void *tmp;
    if ((tmp = malloc(size)) == NULL) 
        return -1;
    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);
    free(tmp);

    return 0;

}

int main() {


    // int arr[5] = {-1, 2, 30, 5, 5};
    // double a[5] = {1.0, 0.11, 1.56, 1.77, 10.77};
    // print_arr_int(arr, 5);
    // print_arr_float(a, 5);

    int a = 10;
    int b = 50;
    printf("a = %d - b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d - b = %d\n", a, b);

    char m = 'k';
    char n = 'y';
    printf("m = %c ||| n = %c\n", m, n);
    swap2(&m, &n, sizeof(char));
    printf("m = %c ||| n = %c\n", m, n);



    return 0;
}