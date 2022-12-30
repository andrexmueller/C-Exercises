#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int sum(int count, ...) {
    int sum = 0;
    va_list ptr;
    va_start(ptr, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(ptr, int);
    }
    va_end(ptr);
    return sum;
}

int min(int count, ...) {
    va_list ptr;
    va_start(ptr, count);
    int _min = va_arg(ptr, int);
    for (int i = 0; i < count; i++) {
        int tmp = va_arg(ptr, int);
        _min = tmp < _min ? tmp : _min;
    }
    va_end(ptr);
    return _min;
}

int max(int count, ...) {
    int _max = INT_MIN;
    va_list ptr;
    va_start(ptr, count);
    for (int i = 0; i < count; i++) {
        int tmp = va_arg(ptr, int);
        _max = tmp > _max ? tmp : _max;
    }
    va_end(ptr);
    return _max;
}


int main() {
    
    printf("\n >> %d", sum(5, 10, 20, 30, 40, 50));
    printf("\n >> %d", min(5, 10,20,-10,-11,30));
    printf("\n >> %d", max(5, 10,20,-10,-11,30));
    
    return 0;
}