#include <stdio.h>
#include <math.h>

#include <string.h> // strcpy
#include "colorprint.h"

#include <stdbool.h>

#define REP(size) for(size_t i=0, length=size; i<length; ++i)
#define REPW(size)  size_t w,length; length=size \
while(w<length)
#define vi  vector<int>
#define vs  vector<string>
#define st  size_t
#define vlu    vector<unsigned long>
#define ul    unsigned long
#define NROWS 5
#define NCOLS 10

// void (*fp)(int);
// float *fp(float);
int *(*x[10])(void);

#pragma region bitwise_operators
void swap1(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap2(int *a, int *b) {
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
int is_odd(int x) {
    return x%2==1;
}
int is_odd2(int x) {
    int and = x&1; // for x = 3:  001 & 011 = 001
    return and==1;
}
int is_even2(int x) {
    return ~x&1;
}
int div_by_8(int x) {
    return !(x&7);
}
int div_by_4(int x) {
    return (x&3) == 0;
}
int reverseSign(int x) {
    return ~x+1;
}
int multBy4(int x) {
    return x << 2;
}
int multBy5(int x) {
    return (x << 2) + x;
}
#pragma endregion bitwise_operators
#pragma region show_bytes()

void show_bytes(unsigned char* start, int len) {
    int i;
    for(i = len-1;i >= 0; --i) {
        printf("%.2x\n", start[i]);
    }
    printf("%10i\n", *((int*)start));
}
#pragma endregion
#pragma region twos_complement
int twos_complement(int x) {
    return (~x)+1;
}
#pragma endregion
int main() {

    if(0) // two's complement
    {
        printf(MAGENTA "\nINTMAX = %i\n\n" RESET, __INT_MAX__);
        printf("%15i\n%15i\n", 0x7fffffff, 0x7fffffff + 2);
        int x = 0x7fffffff;
        show_bytes((unsigned char*)&x,sizeof(int));
        x = twos_complement(0x7fffffff);
        show_bytes((unsigned char*)&x,sizeof(int));
        x = 0x7fffffff + 2;
        show_bytes((unsigned char*)&x,sizeof(int));

    }
    if(0) // show_bytes
    {
        int x = 16;
        for(int i=0;i<8;i++){
            // show_bytes((unsigned char*)&(x),sizeof(int));
            show_bytes((unsigned char*)&x,sizeof(void*));
            x*=16;
        }
    }
    if(0) // bitwise operators
    {
        int a = 1;
        int b = 2;
        // swap2(&a, &b);
        int* isOdd1 = (int[]){is_odd(a),is_odd(b)};
        int* isOdd2 = (int[]){is_odd2(a),is_odd2(b)};

        int isEven = is_even2(3);
        int isDivBy8 = div_by_8(10);
        int notnot = ~~1;
        // printf("%i\n", notnot);
        // printf("%i\n", reverseSign(15436));
        printf("%i\n", multBy4(5));
        return 0;
    }
    if(0)
    {
        printf("%p\t %p\t %p\n", x, &(*x), **x);
        // printf("%s\n", x);
        // printf("%i\n", sizeof(void));
        // fp(1.1);
        // printf("%s", fp);
        int foo = 0;
    }

    if(0)
    {
        char** a;
        char* s1 = "1";
        char* s2 = "2";
        printf("s1 and s2 are %sthe same\n", strcmp(s1,s2) == 0 ? "" : RED "NOT " RESET); // if s1 == s2 returns 0, otherwise returns the difference
    }
    if(0)
    {
        size_t maxValues = 4;
        char** c = (char**) malloc(maxValues * sizeof(char*)); // array of pointers.
        char input[100];
        char* p;
        for(size_t i=0; i<2;++i) {
            scanf("%s\0", input);
            p = (char*) malloc((strlen(input)+1) * sizeof(char));
            c[i] = p;
            strcpy(p, input);
            printf("%x\n", p);
            
        }
        printf("\n\n");
        REP(2) {
            printf("%x\n", &c[i]);
        }
    }

    if(0)
    {
        int i;
        int A[10][5];
        int *p = (int*)A;

        for (i=0, p=(int*)A; i<NROWS*NCOLS; p++, i++)
            *p=0;

        return 0;
    }
    
    if(1) // anonymous struct
    {
        struct {
            int x;
            int y;
        } pt1 = {.x = 1, .y = 2}, \
        pt2 = {.x = 2, .y = 3};
        printf("pt1: %i %i", pt2.x, pt2.y);
    }

}
