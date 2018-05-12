#include <stdio.h>

unsigned int add(unsigned int, unsigned int);
int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int lt(unsigned int, unsigned int);
unsigned int gt(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);

void printBinary(int n) {
while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
}
printf("\n");
}
int main(int argc, char **argv)
{

    unsigned int i, j;

    printf("Enter an integer ");

    scanf("%u", &i);
    printf("\nEnter another integer ");
    scanf("%u", &j);
    printf("\ni + j = %u\n", add(i, j));
    printf("\ni - j = %i\n", sub(i, j));
    printf("\ni * j = %u\n", mul(i, j));
    printf("i > j = %s\n", (gt(i, j) ? "TRUE" : "FALSE"));
    printf("i < j = %s\n", (lt(i, j) ? "TRUE" : "FALSE"));
    printf("jth byte of i = %ux\n", getByte(i, j));

    return 0;
}
/*
ONLY THESE ARE ALLOWED: &, |, ^, <<, >>, ~) along with !, =, ==, !=, && and ||
*/
unsigned int add(unsigned int i, unsigned int j)
{
    unsigned int xor = i ^ j;
    unsigned int commonBits = i & j;
    unsigned int shifted = commonBits << 1;
    if (!commonBits) return xor;
    return add (xor, shifted);
}

int sub(unsigned int i, unsigned int j)
{
    int minusJ = (int)add(~(int)j,1);
    return (int)(add(i,minusJ));
}

unsigned int mul(unsigned int i, unsigned int j)
{
    unsigned int res = 0;
    unsigned int k = 0;

    while(sub(j,k)) {
        res = add(res,i);
        k = add(k, 1);
    }
    return res;
}

/* returns non-zero if i is less than j or zero otherwise */
unsigned int lt(unsigned int i, unsigned int j)
{
    int comparison = 0;
    do {
        if(i&1 && j&0) comparison = 0;
        else if(i&0 && j&1) comparison = 1;
        i >>= 1;
        j >>= 1;
    } while(i && j);
    if(i) return 0;
    if(j) return 1;
    return comparison;
}

/* returns non-zero if i is greater than j or zero otherwise */
unsigned int gt(unsigned int i, unsigned int j)
{
    int comparison = 0;
    do {
        if(i&1 && j&0) comparison = 1;
        else if(i&0 && j&1) comparison = 0;
        i >>= 1;
        j >>= 1;
    } while(i && j);
    if(i) return 1;
    if(j) return 0;
    return comparison;
}

/* returns the jth byte of i */
// starting from 1
unsigned int getByte(unsigned int i, unsigned int j)
{
    int s = sub(j,1); // starts from 1, not 0
    int m = mul(8, s);
    int res = i >> m;
    return res;
}