#include <stdio.h>
#include <stdlib.h>
#define LEN_A 10

/* function declarations */
void print_array(int[], int);
void reverse(int[], int);
double average(int[], int);
void insert(int[], int, int, int);
int less_than_average(int[], int);
void rotate_right(int[], int, int);
void array_copy(int[], int[], int);
void initialize(int[], int, int);
void evens_on_left(int[], int);
int find(int A[], int len, int x);
int find_last(int A[], int len, int x);
int contains_dup(int A[], int len);

int main(int argc, char **argv)
{
  printf("Hello, there are some questions you did not require, but I did them anyways, just for fun :)\n");
  int A[] = {9, 505, 321, 117, 27, 64, 13, 9, 12, 208};
  int B[LEN_A+1];
  int newValue=505;

  printf("A[] is:\n");
  print_array(A, LEN_A);

  initialize(B, LEN_A+1, 0);
  printf("B[] is:\n");
  print_array(B, LEN_A+1);

  array_copy(B, A, LEN_A);
  printf("but now it's\n");
  print_array(B, LEN_A+1);

  insert(B, newValue, 0, LEN_A);
  printf("and after inserting %d at the beginning it's\n", newValue);
  print_array(B, LEN_A+1);

  printf("The average of A[] is %g\n", average(A,LEN_A));
  printf("There are %d items in A[] less than this.\n", less_than_average(A,LEN_A));

  reverse(A, LEN_A);
  print_array(A, LEN_A);

  rotate_right(A, LEN_A, 3);
  print_array(A, LEN_A);

  evens_on_left(A, LEN_A);
  print_array(A, LEN_A);

  printf("The index of the first occurrence of %d is %d.\n", 9, find(A, LEN_A, 9));
  printf("The index of the last occurrence of %d is %d.\n", 9, find_last(A, LEN_A, 9));

  if (contains_dup(A, LEN_A))
    printf("A[] contains a dup\n");
  else
    printf("A[] doesn't contain a dup\n");

  if (contains_dup(B, LEN_A+1))
    printf("B[] contains a dup\n");
  else
    printf("B[] doesn't contain a dup\n");

  printf("Second largest item in A is %i. I think you forgot this method in assignment code :)\n", secondLargest(A, LEN_A));
  return 0;
}

/* functions implementation */

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen). */
void print_array(int A[], int length) {
  // not one byte is wasted :)
  char* output = (char*) malloc(length * sizeof(char) + sizeof(" ,") * length + sizeof("()"));
  char* next = (char*) malloc(sizeof(int) + sizeof(" ,"));
  strcat(output, "(");
  for(int i=0; i<length; ++i) {
    sprintf(next, "%i, ", A[i]);
    strcat(output, next);
  }
  output[strlen(output) - 2] = '\0';
  printf("%s)\n",output);
  free(output);
  free(next);
}

/* returns the average of the items in A[] or 0.0 if A is empty */
double average(int A[], int length) {
  /* for now return 1.0 as a placeholder.  We do this just so that the program
     compiles without warning until we've finished */
     double average;
     int sum = 0;
     for(int i=0; i<length; ++i) {
       sum += A[i];
     }
     average = sum / length;
  return average;
}

/* returns the number of items in A that are less than the
   average of the items in A */
int less_than_average(int A[], int length) {
  /* for now return 0 as a placeholder. We do this just so that the program
     compiles without warning until we've finished */
     double avrg = average(A, length);
     size_t num_avrg = 0;
     for(int i=0; i<length; ++i){
       if(A[i] < avrg) ++num_avrg;
     }
  return num_avrg;
}

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length) {
  int temp;
  for(int i=0; i<length/2; ++i) {
    temp = A[i];
    A[i] = A[length - 1 - i];
    A[length - 1 - i] = temp;
  }
}

/* returns the second largest item in A[], or -1 if len < 2 */
int secondLargest(int A[], int length) {
  /* for now return 0 as a placeholder.  We do this just so that the program
     compiles without warning until we've finished */
     int biggest[2] = {A[0],A[0]};
     for(int i=0; i<length; ++i) {
       if(A[i] < biggest[0]) {
        biggest[1] = biggest[0];
        biggest[0] = A[i];
       }
     }
  return biggest[1];
}

/* rotates the values in the array numPlaces to the right */
/* for example, if A[] is initially 10,20,30,40,50, and numPlaces=2 */
/* after the function finishes, A[] would be 40,50,10,20,30 */
void rotate_right(int A[], int length, int numPlaces) {
  numPlaces = numPlaces % length;
  int* temp = (int*) malloc(sizeof(int) * numPlaces);
  for(int i=0; i<numPlaces; ++i) {
    temp[i] = A[length - numPlaces + i];
  }
  for(int i=length-1; i>=numPlaces; --i) {
    A[i] = A[i-numPlaces];
  }
  for(int i=0; i<numPlaces; ++i) {
    A[i] = temp[i];
  }
  
}

/* inserts the value n in A[] at the given index and shifts
   all other values up one position.  A[] contains length items.

   It is up to the caller to make sure that there is enough space
   in A[] to accomodate the new item, and that the index is valid. */
void insert(int A[], int n, int index, int length) {
  // assuming A has spare space
  for(int i=length; i>index; --i) {
    A[i] = A[i-1];
  }
  A[index] = n;
}

/* copies the first numItems from S to D. */
void array_copy(int D[], int S[], int numItems) {
  for(int i=0; i<numItems; ++i) {
    D[i] = S[i];
  }
}


/* sets the first len elements of A to initialValue */
void initialize(int A[], int len, int initialValue) {
  for(int i=0; i<len; ++i) {
    A[i] = initialValue;
  }
}

/* shuffles the values in A so that the even values
   are all to the left of the odd values */
void evens_on_left(int A[], int len) {
  int* even = (int*) malloc(len * sizeof(int));
  int numEven = 0;
  for(int i=0; i<len; ++i) {
    if(A[i] % 2 == 0) {
      even[numEven] = A[i];
      ++numEven;      
    }
  }
  
  int numOdd = 0;
  for(int i=len-1; i>=0; --i) {
    if(A[i] % 2 != 0){
      A[len - 1 - numOdd] = A[i];
      ++numOdd;
    }
  }
  for(int i=0; i<numEven; ++i) {
    A[i] = even[i];
  }
}

/* returns the index of the first occurrence of
   x in A[] or -1 if x doesn't exist in A[] */
int find(int A[], int len, int x) {
  for(int i=0; i<len; ++i) {
    if(A[i] == x) return i;
  }
  return -1;
}

/* returns the index of the last occurrence of
 * x in A[] or -1 if x doesn't exist in A[] */
int find_last(int A[], int len, int x) {
  for(int i=len-1; i>=0; --i) {
    if(A[i] == x) return i;
  }
  return -1;
}

/* returns 1 if there is at least one element in A[]
   that is contained elsewhere in A[], or 0 if there isn't */
int contains_dup(int A[], int len) {
  // parallel for loop for performance
  #pragma omp parallel for
  for(int i=0;i<len;++i) {
    #pragma omp parallel for
    for(int k=0;k<len;++k) {
      if(i != k && A[i] == A[k]) return 1;
    }
  }
  return 0;
}
