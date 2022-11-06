#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include "rational_numbers.h"


// utils
void print(rational_t number) {
    printf("\n\t%d/%d\n", number.numerator, number.denominator);
}

void max_min(int* x, int* y) {
    if (*x >= *y) return;
    int t = *x;
    *x = *y;
    *y = t;
    return;
}

int abs(int n) {
    n = n >= 0 ? n : -n;
    return n;
}

int gcd(int a, int b) {
    if (a == 0 || b == 0) return 0;
    a = abs(a);
    b = abs(b);
    max_min(&a, &b);
    while (a > b) {
        a -= b;
        max_min(&a, &b);
    }
    return a;
}

rational_t fix_sign(rational_t r) {
    int sign_p = r.numerator >= 0 ? 1 : -1;
    int sign_q = r.denominator > 0 ? 1 : -1;
    r.numerator = abs(r.numerator) * (sign_p * sign_q);
    r.denominator = abs(r.denominator);
    return r; 
}

void check_rational_numbers_equal(rational_t r1, rational_t r2) {
    print(r1);
    print(r2);
    if (r1.numerator == r2.numerator && r1.denominator == r2.denominator) printf(">> Teste: Correct.\n");
    else printf(">> Incorrect!\n");
}


////////// solution

rational_t absolute(rational_t r) {
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);
    return r;
}

rational_t reduce(rational_t r) {
    if (r.numerator == 0){
        r.denominator = 1;
        return r;
    }
    int g = gcd(r.numerator, r.denominator);
    if (g == 0) return r;
    r.numerator /= g;
    r.denominator /= g;
    r = fix_sign(r);
    return r;
}

rational_t add(rational_t r1, rational_t r2) {
    r1 = fix_sign(r1);
    r2 = fix_sign(r2);
    rational_t sum;
    sum.numerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
    sum.denominator = r1.denominator * r2.denominator;
    sum = fix_sign(sum);
    sum = reduce(sum);
    return sum;
}

rational_t subtract(rational_t r1, rational_t r2) {
    r2.numerator *= -1;
    r1 = fix_sign(r1);
    r2 = fix_sign(r2);
    return add(r1, r2);
}

rational_t multiply(rational_t r1, rational_t r2) {
    r1 = fix_sign(r1);
    r2 = fix_sign(r2);
    rational_t m = { r1.numerator * r2.numerator, r1.denominator * r2.denominator };
    m = reduce(m);
    return m;
}

rational_t divide(rational_t r1, rational_t r2) {
    rational_t r2p = { r2.denominator, r2.numerator };
    return multiply(r1, r2p);
}

rational_t exp_rational(rational_t r, int n) {
    if (n == 0) {
        rational_t res = { 1 , 1 };
        return res;
    }
    int sign_n = n > 0 ? 1 : -1;
    n = abs(n);
    int p = (int) pow(r.numerator, n);
    int q = (int) pow(r.denominator, n);
    rational_t res = { p , q };
    if (sign_n == -1) {
        int temp = res.numerator;
        res.numerator = res.denominator;
        res.denominator = temp;
    }
    res = fix_sign(res);
    res = reduce(res);
    return res;
}

float exp_real(float x, rational_t r) {
    //float res = (float) pow(r.numerator, x) / (float) pow(r.denominator, x);
    float exponent = (float)r.numerator / (float)r.denominator;
    float res = pow(x, exponent);
    return res;
}


///////////////// main
int main(int argc, char* argv[]) {

    //int x = atoi(argv[1]);
    //int y = atoi(argv[2]);
    
    // rational_t r1 = { 1, 2 };
    // rational_t r2 = { -2, 3 };
    // rational_t expected = { -1, 6 };
    // rational_t actual = add(r1, r2);
    // check_rational_numbers_equal(expected, actual);
    rational_t r = { -3, 5 };
    int16_t n = -3;
    rational_t expected = { -125, 27 };
    rational_t actual = exp_rational(r, n);
    check_rational_numbers_equal(expected, actual);

    
    
    return 0;
}

