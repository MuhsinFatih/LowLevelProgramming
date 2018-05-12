#include <stdio.h>

int main(int argc, char **argv) {
  int x=10, y=20;
  int *p;
  int *q;

  p=&x;
  q=&y;

  printf("x=%d, y=%d, p=%p, q=%p\n", x, y, p, q);
  printf("sizeof(int) is %lu\n", sizeof(int));

  *p=*p+1;
  
  printf("x=%d, y=%d, p=%p, q=%p\n", x, y, p, q);
  return 0;
}

