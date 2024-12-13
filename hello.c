#include <stdio.h>
#include <stdbool.h>
#include "hello.h"

struct car {
    char *name;
    float price;
    int speed;
};

int main(void) {
    printf("Hello World\n");

    int i = 2;
    float f = 3.14;

    char *s =  "Hello World";
    
    printf("%s i = %d and f = %f!\n", s, i ,f);

    bool x = false;

    if (!x) {
        printf("x is not true: %d\n", x);
    }

    int a = 9999;
    // %zu is the format specifier for type size_t
    printf("%zu\n", sizeof a); // Prints 4 on my system
    printf("%zu\n", sizeof(2 + 7)); // Prints 4 on my system
    printf("%zu\n", sizeof 3.14); // Prints 8 on my system

    x = true;

    while(x==true) {
        if (a == 10001) 
        {
            x = false;
        } else {
            printf("incrementing a: %d", a);
            a++;
            printf(" %d\n", a);
        }
    }

    add(1,4);

    //Pointers

    int o = 1;
    int *p = &o;

    printf("%d %d\n", o, *p);
    *p+=o;
    printf("%d %d\n", o, *p);

    float farray[4];
    farray[0] = 1.0;
    farray[1] = 4.0;
    printf("%f\n", farray[3]);

    printf("%zu\n", sizeof(farray)/sizeof(int));

    int b[5] = {22, 44, 11, 32, 43};

    for (int index = 0; index < (sizeof(b)/sizeof(int)); index++) {
        printf("Array B, index: %d is %d\n", index, b[index]);
    }

    int c[100] = {0}; //shortcut to fill 100 zeros in the array


    struct car saturn = {"Saturn SL.2", 16000.99, 175};

    printf("Car Name: %s\nCar Price: %f\nCarSpeed: %d\n", saturn.name, saturn.price, saturn.speed);

    FILE *fp;
    char line[1024];
    int linecount = 0;
    fp = fopen("quote.txt", "r");
    while (fgets(line, sizeof line, fp) != NULL) {
        printf("%d: %s", ++linecount, line);
    } 
    printf("\n");
    fclose(fp);


    //Pick up on: Pointers II: Arithmetic page 69
    //https://beej.us/guide/bgc/pdf/bgc_usl_c_1.pdf
}

void add(int a, int b) {
    printf("%d + %d = %d\n", a, b, a+b);
}
