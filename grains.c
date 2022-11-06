#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t square(uint8_t index);
uint64_t total(void);


uint64_t square(uint8_t index) {
    if (index < 1 || index > 64) return 0;
    int sq = 1;
    uint64_t on_sq = 1;
    while (sq < index) {
        on_sq *= 2;
        sq++;
    }
    return on_sq;
}

uint64_t total(void){
    uint64_t t = 0;
    for (int i = 1; i <= 64; i++) {
        t += square(i);
    }
    return t;
}



int main() {

    uint64_t x = square(64);
    printf("%" PRIu64 "\n", x);

    uint64_t t = total();
    printf("%" PRIu64 "\n", t);

    

}