#include <stdio.h>


#define print(X) _Generic((X),          \
            int: print_int,             \
            double: print_double,       \
            my_t: print_myt)(X)


#define guess_the_type(X) _Generic((X),         \
            int: "integer",\
            double: "double float",\
            char *: "good old string", \
            char: "char",\
            my_type: "type i've diefined"\
)


typedef struct my_type {
    int x;
    int y;
} my_type;


typedef struct myt {
    char *s;
    int n;
} my_t;



void print_int(int a) {
    printf(" _ %d _\n", a);
}

void print_double(double x) {
    printf(" _ %f _\n", x);
}

void print_myt(my_t x) {
    printf("  %s  - ", x.s);
    printf(" .. %d \n", x.n);
}


int main() {


    double x = 10.13;
    int a  = 10;
    my_t q = {"andre", 10};
    my_type z = {10 , 20};
    char *nome = "andre";
    char h = 'z';
    print(x);
    print(a);
    print(q);



    printf("\n==============x===============\n");
    printf("Guessing type\n");
    printf(" >> %s \n", guess_the_type(x));
    printf(" >> %s \n", guess_the_type(a));
    printf(" >> %s \n", guess_the_type(z));
    printf(" >> %s \n", guess_the_type(nome));
    printf(" >> %s \n", guess_the_type(h));

    return 0;
}